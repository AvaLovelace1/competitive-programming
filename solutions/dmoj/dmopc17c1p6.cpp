/*
 Solution to DMOPC '17 Contest 1 P6 - Land of the Carrot Trees by Ava Pun
 Key concepts: square root query bucketing, graph theory
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int N, Q;
int BLOCK_SZ;
unordered_map<int, pii> adj[MAX], meta[MAX];
piii quers[MAX];
int comp[MAX], dist[MAX];
bool vis[MAX];
int compCnt = 0, blockCnt = 0;

void dfs(int u, int p) {
    comp[u] = compCnt;
    vis[u] = 1;
    for (auto e : adj[u]) {
        int v = e.f, w = e.s.s, b = e.s.f;
        if (v != p && b != blockCnt) {
            dist[v] = dist[u] ^ w;
            dfs(v, u);
        }
    }
}

int dfsMeta(int u, int p, int t) {
    if (comp[u] == comp[t]) {
        return dist[u] ^ dist[t];
    }
    for (auto e : meta[comp[u]]) {
        int v = e.f, a = e.s.f, w = e.s.s;
        if (comp[v] != p) {
            int ans = dfsMeta(v, comp[u], t);
            if (ans != -1) {
                return ans ^ w ^ dist[u] ^ dist[a];
            }
        }
    }
    return -1;
}

inline int solve(int a, int b) {
    return dfsMeta(a, -1, b);
}

int main() {
    
    scanf("%d%d", &N, &Q);
    BLOCK_SZ = 1000;
    int a, b, d;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a][b] = {0, d};
        adj[b][a] = {0, d};
    }
    
    char c;
    for (int i = 1; i <= Q; i++) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'A') {
            scanf("%d", &d);
            quers[i] = {d, {a, b}};
        } else if (c == 'R') {
            quers[i] = {-1, {a, b}};
        } else {
            quers[i] = {-2, {a, b}};
        }
    }
    
    for (int l = 1; l <= Q; l += BLOCK_SZ) {
        blockCnt++;
        compCnt = 0;
        int r = min(Q, l + BLOCK_SZ - 1);
        for (int i = l; i <= r; i++) {
            if (quers[i].f >= -1) {
                a = quers[i].s.f, b = quers[i].s.s;
                if (adj[a].find(b) != adj[a].end()) {
                    adj[a][b].f = blockCnt;
                    adj[b][a].f = blockCnt;
                }
            }
        }
        FILL(vis, 0);
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                compCnt++;
                dist[i] = 0;
                dfs(i, -1);
            }
        }
        for (int i = 1; i <= compCnt; i++) {
            meta[i].clear();
        }
        for (int i = l; i <= r; i++) {
            if (quers[i].f >= -1) {
                a = quers[i].s.f, b = quers[i].s.s;
                if (adj[a].find(b) != adj[a].end()) {
                    meta[comp[a]][b] = {a, adj[a][b].s};
                    meta[comp[b]][a] = {b, adj[a][b].s};
                }
            }
        }
        for (int i = l; i <= r; i++) {
            a = quers[i].s.f, b = quers[i].s.s;
            if (quers[i].f == -1) {
                adj[a].erase(b), adj[b].erase(a);
                meta[comp[a]].erase(b), meta[comp[b]].erase(a);
            } else if (quers[i].f >= 0) {
                adj[a][b].s = adj[b][a].s = quers[i].f;
                meta[comp[a]][b] = {a, quers[i].f};
                meta[comp[b]][a] = {b, quers[i].f};
            } else {
                printf("%d\n", solve(a, b));
            }
        }
    }
    
    return 0;
}
