/*
 Solution to DMOPC '13 Contest 3 P5 - A Romantic Dinner by Ava Pun
 Key concepts: knapsack dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int M, U, R;
int V[151], T[151], F[151];
int dp[151][301][101];

int solve(int i, int j, int k) {
    if (dp[i][j][k] == -1) {
        if (i == 0) {
            dp[i][j][k] = 0;
        } else {
            if (j < T[i] || k < F[i]) {
                dp[i][j][k] = solve(i - 1, j, k);
            } else {
                dp[i][j][k] = max(solve(i - 1, j - T[i], k - F[i]) + V[i], solve(i - 1, j, k));
            }
        }
    }
    return dp[i][j][k];
}

int main() {
    
    scanf("%d%d%d", &M, &U, &R);
    for (int i = 1; i <= R; i++) {
        scanf("%d%d%d", &V[i], &T[i], &F[i]);
    }
    memset(dp, -1, sizeof(dp));
    
    printf("%d", solve(R, M, U));
    
    return 0;
}
