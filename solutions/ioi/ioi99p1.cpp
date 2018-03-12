/*
 Solution to IOI '99 P1 - Little Shop of Flowers by Ava Pun
 Key concepts: knapsack dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int V, F;
int arr[101][101];
int dp[101][101];
int ans[101];

int solve(int i, int j) {
    
    if (dp[i][j] == -1) {
        if (i == 0 || j == 0) {
            dp[i][j] = 0;
        } else if (i == j) {
            dp[i][j] = solve(i - 1, j - 1) + arr[i][j];
        } else {
            dp[i][j] = max(solve(i - 1, j - 1) + arr[i][j], solve(i - 1, j));
        }
    }
    return dp[i][j];
}

int main() {
    
    scanf("%d%d", &F, &V);
    for (int i = 1; i <= F; i++) {
        for (int j = 1; j <= V; j++) {
            scanf("%d", &arr[j][i]);
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(V, F));

    int j = F;
    for (int i = V; i > 0; i--) {
        if (dp[i][j] == dp[i - 1][j - 1] + arr[i][j]) {
            ans[j] = i;
            j--;
        }
    }
    
    for (int i = 1; i <= F; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}
