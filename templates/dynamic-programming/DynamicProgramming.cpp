/*
 ~ Dynamic Programming ~
 
 A collection of random DP problems.
 
 Coin Change Problem
 What is the minimum number of coins needed to make exact change?
 Somewhat related to the knapsack problem.
 Time complexity: O(NM)
 
 Edit Distance Problem
 What is the minimum cost edit distance between two strings,
 given a cost for deleting a character, inserting a character, and replacing a character?
 Time complexity: O(NM)
 
 Coin Game Problem
 A game where you and an opponent take turns taking a coin from either side of a line of coins.
 What is the maximum score you can obtain, if both you and your opponent play perfectly?
 Time complexity: O(N^2)
 
 Weighted Scheduling Problem
 Find maximum value given tasks with associated values, start times, and lengths.
 (You cannot do two tasks at the same time.)
 Time complexity: O(NlogN)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

int T;
int N, M;
int arr[MAX];
piii arr1[MAX];
int dp[MAX];
int dp1[MAX][MAX];
int D, I, R;
string A, B;

int change() {
    
    fill(dp, dp + M + 1, INF);
    dp[0] = 0;
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    return dp[M];
}

int editDist() {
    
    for (int i = 0; i <= A.length(); i++) {
        for (int j = 0; j <= B.length(); j++) {
            if (i == 0 && j == 0) {
                dp1[i][j] = 0;
            } else if (i == 0) {
                dp1[i][j] = j * I;
            } else if (j == 0) {
                dp1[i][j] = i * D;
            } else {
                if (A[i - 1] == B[j - 1]) {
                    dp1[i][j] = dp1[i - 1][j - 1];
                } else {
                    dp1[i][j] = min(min(dp1[i - 1][j] + D, dp1[i][j - 1] + I), dp1[i - 1][j - 1] + R);
                }
            }
        }
    }
    
    return dp1[A.length()][B.length()];
    
}

int coinGame(int l, int r) {
    // assumes the array is a prefix sum array
    if (dp1[l][r] == -1) {
        if (l == r) {
            dp1[l][r] = arr[r] - arr[l - 1];
        } else {
            dp1[l][r] = arr[r] - arr[l - 1] - min(coinGame(l + 1, r), coinGame(l, r - 1));
        }
    }
    return dp1[l][r];
}

int sched() {
    
    sort(arr1, arr1 + N);
    
    for (int i = N - 1; i >= 0; i--) {
        int start = 0, end = N, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (arr1[mid].first.first >= arr1[i].first.first + arr1[i].first.second) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        dp[i] = max(arr1[i].second + dp[start], dp[i + 1]);
    }
    
    return dp[0];
}


int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    if (T == 1) {
        
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        cout << "Min number of coins to make change: " << change() << "\n";
        
    } else if (T == 2) {
        
        cin >> A >> B >> D >> I >> R;
        cout << "Edit distance: " << editDist() << "\n";
        
    } else if (T == 3) {
        
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        memset(dp1, -1, sizeof(dp1));
        cout << "Maximum score obtainable by first player: " << coinGame(1, N) << "\n";
        
    } else if (T == 4) {
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr1[i].first.first >> arr1[i].first.second >> arr1[i].second;
        }
        cout << "Maximum value obtainable: " << sched() << "\n";

    }
    
    return 0;
    
}
