/*
 Solution to CCO '10 P2 - Tree Pruning by Ava Pun
 Key concepts: dynamic programming on trees
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MAX = 305;

int N, D;
int arr[MAX];
vector<int> adj[MAX];
int dp[MAX][2 * MAX];

void solve(int n) {
    
    dp[n][N] = 1;
    if (adj[n].size() == 1) {
        int c1 = adj[n][0];
        solve(c1);
        for (int i = -N; i <= N; i++) {
            int idx = i + arr[n] + N;
            if (idx >= 0 && idx <= 2 * N) {
                dp[n][idx] = min(dp[n][idx], dp[c1][i + N]);
            }
        }
    } else if (adj[n].size() == 2) {
        int c1 = adj[n][0], c2 = adj[n][1];
        solve(c1), solve(c2);
        for (int i = -N; i <= N; i++) {
            for (int j = -N; j <= N; j++) {
                int idx = i + j + arr[n] + N;
                if (idx >= 0 && idx <= 2 * N) {
                    dp[n][i + j + arr[n] + N] = min(dp[n][i + j + arr[n] + N], dp[c1][i + N] + dp[c2][j + N]);
                }
            }
        }
    } else {
        dp[n][arr[n] + N] = 0;
    }
    
}

int main() {
    
    scanf("%d%d", &N, &D);
    int n, val, c, v;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &n, &val, &c);
        arr[n] = val ? 1 : -1;
        while (c--) {
            scanf("%d", &v);
            adj[n].push_back(v);
        }
    }
    
    memset(dp, INF, sizeof(dp));
    solve(0);
    
    printf("%d", dp[0][D + N] == INF ? -1 : dp[0][D + N]);
    
    return 0;
}
