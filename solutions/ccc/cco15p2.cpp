/*
 Solution to CCO '15 P2 - Artskjid by Ava Pun
 Key concepts: graph theory, bitmask dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

int N, M;
int adj[20][20];
int dp[20][1 << 18];

int solve(int n, int s) {
    s |= 1 << n;
    if (dp[n][s] == -1) {
        if (n == 0) {
            dp[n][s] = 0;
        } else {
            dp[n][s] = INT_MIN;
            for (int i = 0; i < N; i++) {
                if (adj[i][n] != -1 && (s & (1 << i))) {
                    dp[n][s] = max(dp[n][s], solve(i, s & ~(1 << n)) + adj[i][n]);
                }
            }
        }
    }
    return dp[n][s];
}

int main() {
    
    memset(adj, -1, sizeof(adj));
    scanf("%d%d", &N, &M);
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a][b] = d;
    }
    
    memset(dp, -1, sizeof(dp));
    
    int ans = INT_MIN;
    for (int i = 0; i < 1 << (N - 1); i++) {
        ans = max(ans, solve(N - 1, i));
    }
    printf("%d", ans);
    
    return 0;
}
