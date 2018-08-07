/*
 Solution to CCC '02 S4 - Bridge Crossing by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int M, Q;
int arr[101];
string names[101];
int dp[101];
int parent[101];
int child[101];

int findMax(int i, int j) {
    int ans = INT_MIN;
    for (int k = i; k <= j; k++) {
        ans = max(ans, arr[k]);
    }
    return ans;
}

int solve(int n) {
    if (dp[n] == -1) {
        if (n == 0) {
            dp[n] = 0;
        } else {
            dp[n] = INT_MAX;
            for (int i = n; n - i + 1 <= M && i >= 1; i--) {
                int ans = findMax(i, n) + solve(i - 1);
                if (ans < dp[n]) {
                    dp[n] = ans;
                    parent[n] = i - 1;
                }
            }
        }
    }
    return dp[n];
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> names[i] >> arr[i];
    }
    
    parent[0] = 0;
    fill(dp, dp + Q + 1, -1);
    cout << "Total Time: " << solve(Q) << "\n";
    int idx = Q;
    while (idx != parent[idx]) {
        child[parent[idx]] = idx;
        idx = parent[idx];
    }
    
    while (idx < Q) {
        int i = idx;
        while (i < child[idx]) {
            i++;
            cout << names[i] << " ";
        }
        idx = child[idx];
        cout << "\n";
    }
    
    return 0;
}
