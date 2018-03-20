/*
 Solution to ECOO '13 R3 P4 - Tour de Force by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N;
pii arr[1001];
int dp[1001][5];

int solve(int i, int j) {
    
    if (i >= N) {
        return 0;
    }
    
    if (dp[i][j] == -1) {
        if (j == 4) {
            dp[i][j] = arr[i].first - 1 + solve(i + 1, 0);
        } else {
            dp[i][j] = max(arr[i].first - 1 + solve(i + 1, 0), arr[i].first + arr[i].second + solve(i + 1, j + 1));
        }
    }
    return dp[i][j];
}

int main() {
    
    for (int cnt = 1; cnt <= 10; cnt++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &arr[i].first, &arr[i].second);
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, 0));
    }
    
    return 0;
    
}
