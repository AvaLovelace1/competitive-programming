/*
 Solution to Strategy Meeting by Ava Pun
 Key concepts: bitmask dynamic programming, graph theory
 */
 
#include <bits/stdc++.h>

using namespace std;

const int MOD = 13371337;
int T, N;
bool adj[16][16];
int dp[16][(1 << 16) + 5];

int solve(int n, int s) {
    if (dp[n][s] == -1) {
        if (!(s & (1 << n))) {
            dp[n][s] = 0;
        } else if (n == 0 && s == 1) {
            dp[n][s] = 1;
        } else {
            dp[n][s] = 0;
            for (int i = 0; i < N; i++) {
                if (adj[i][n] && (s & (1 << i))) {
                    dp[n][s] += solve(i, s & ~(1 << n));
                    dp[n][s] %= MOD;
                }
            }
        }
    }
    return dp[n][s];
}

int main() {
    
    scanf("%d", &T);
    
    while (T--) {
        
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &adj[i][j]);
            }
        }
        
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 1 << (N - 1); i < 1 << N; i++) {
            ans += solve(N - 1, i);
            ans %= MOD;
        }
        printf("%d\n", ans);
        
    }
    
    return 0;
}
