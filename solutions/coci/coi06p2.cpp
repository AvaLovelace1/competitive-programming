/*
 Solution to COI '06 #2 Policija by Ava Pun
 Key concepts: graph theory, Tarjan's, articulation points, bridges, binary lifting
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int MAXL = 17;

int N, M, Q;
vi adj[MAX];
int dfn[MAX], low[MAX], out[MAX];
bool vis[MAX];
int par[MAX], depth[MAX];
int cnt = 0;
int dp[MAX][MAXL + 1];

void tarj(int u, int prev) {
    
    dfn[u] = low[u] = ++cnt;
    vis[u] = true;
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            tarj(v, u);
            low[u] = min(low[u], low[v]);
        } else if (v != prev && dfn[v] < dfn[u]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    out[u] = cnt;
    
}

bool desc(int u, int v) {
    return dfn[u] >= dfn[v] && out[u] <= out[v];
}

int anc(int u, int d) {
    int n = MAXL;
    while (d) {
        if (d - (1 << n) >= 0) {
            u = dp[u][n];
            d -= 1 << n;
        } else {
            n--;
        }
    }
    return u;
}

int main() {
    
    scanf("%d%d", &N, &M);
    int t, a, b, c, d;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    tarj(1, -1);
    FILL(dp, -1);
    for (int i = 1; i <= N; i++) {
        dp[i][0] = par[i];
    }
    for (int j = 1; (1 << j) < N; j++) {
        for (int i = 1; i <= N; i++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (dfn[c] < dfn[d]) {
                swap(c, d);
            }
            printf(low[c] <= dfn[d] || desc(a, c) == desc(b, c) ? "yes\n" : "no\n");
        } else {
            scanf("%d%d%d", &a, &b, &c);
            bool ac = desc(a, c), bc = desc(b, c);
            if (!ac && !bc) {
                printf("yes\n");
            } else if (ac && bc) {
                int p1 = anc(a, depth[a] - depth[c] - 1);
                int p2 = anc(b, depth[b] - depth[c] - 1);
                printf(p1 == p2 || (low[p1] < dfn[c] && low[p2] < dfn[c]) ? "yes\n" : "no\n");
            } else {
                if (!ac) {
                    swap(a, b);
                }
                int p = anc(a, depth[a] - depth[c] - 1);
                printf(low[p] < dfn[c] ? "yes\n" : "no\n");
            }
        }
    }
    
    return 0;
}
