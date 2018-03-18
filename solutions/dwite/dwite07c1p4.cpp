/*
 Solution to DWITE '07 R1 #4 - Stacks of Blocks by Ava Pun
 Key concepts: knapsack dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3F3F3F3F;

int H, S;
int arr[11];
int dp[101][11];

int solve(int i, int j) {
    
    if (i == 0) {
        return 0;
    }
    
    if (j < 0 || j >= S) {
        return INF;
    }
    
    if (dp[i][j] == -1) {
        if (i < arr[j]) {
            dp[i][j] = solve(i, j - 1);
        } else {
            dp[i][j] = min(solve(i - arr[j], j - 1) + 1, solve(i, j - 1));
            
        }
    }
    
    return dp[i][j];
}

int main() {
    
    scanf("%d%d", &H, &S);
    for (int i = 0; i < S; i++) {
        scanf("%d", &arr[i]);
    }
    
    memset(dp, -1, sizeof(dp));
    int ans = solve(H, S - 1);
    
    printf("%d", ans != INF ? ans : 0);
    
    return 0;
    
}
