/*
 Solution to CCO '14 P3 - Werewolf by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, bool> pii;
const int MOD = 1e9 + 7;
const int MAX = 205;

int N, W, M;
vector<pii> adj[MAX];
int indeg[MAX];
ll dp[MAX][MAX][2];
bool vis[MAX];

void solve(int n, bool w) {
    
    if (w) {
        dp[n][1][w] = 1;
    } else {
        dp[n][0][w] = 1;
    }
    
    for (pii p : adj[n]) {
        int m = p.first;
        if (!vis[m]) {
            solve(m, 0);
            solve(m, 1);
            vis[m] = true;
        }
        for (int i = W; i >= 0; i--) {
            ll ans = 0;
            for (int j = 0; j <= i; j++) {
                if (w) {
                    if (p.second) {
                        ans += dp[m][j][0] * dp[n][i - j][1] % MOD;
                    } else {
                        ans += dp[m][j][1] * dp[n][i - j][1] % MOD;
                    }
                } else {
                    ans += (dp[m][j][0] * dp[n][i - j][0] % MOD + dp[m][j][1] * dp[n][i - j][0] % MOD) % MOD;
                }
                ans %= MOD;
            }
            dp[n][i][w] = ans;
        }
    }
    
}

int main() {
    
    scanf("%d%d%d", &N, &W, &M);
    int a, b;
    char c;
    while (M--) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'A') {
            adj[a].push_back({b, 1});
        } else {
            adj[a].push_back({b, 0});
        }
        indeg[b]++;
    }
    
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) {
            adj[0].push_back({i, 1});
        }
    }
    
    solve(0, 0);    
    printf("%lld", dp[0][W][0]);
    
    return 0;
    
}
