/*
 Solution to USACO '19 Open P1 - Tree Boxes by Ava Pun
 Key concepts: lowest common ancestor
 */

#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int MAXL = 17;

int N, Q;
vi adj[MAX];
int par[MAX], depth[MAX];
int dp[MAX][MAXL + 5];
pii sz[MAX], pos[MAX];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

pii dfsSz(int u, int p) {
    pii ans = {0, 0};
    int children = 0;
    for (int v : adj[u]) {
        if (v != p) {
            children++;
            pii sizeU = dfsSz(v, u);
            ans.f += sizeU.f;
            ans.s += sizeU.s;
        }
    }
    if (children == 0) {
        ans = {1, 1};
    } else if (children == 1) {
        ans.f++;
    }
    sz[u] = ans;
    return ans;
}

void dfsPos(int u, int p) {
    vector<pair<pii, int>> sizes;
    int x = 0, y = 0;
    int children = 0;
    for (int v : adj[u]) {
        if (v != p) {
            children++;
            sizes.pb({sz[v], v});
            x += sz[v].f;
        }
    }
    if (children == 1) {
        for (auto p : sizes) {
            pos[p.s] = {pos[u].f + 1, pos[u].s};
        }
    } else {
        sort(sizes.begin(), sizes.end());
        for (auto p : sizes) {
            x -= p.f.f;
            pos[p.s] = {pos[u].f + x, pos[u].s + y};
            y += p.f.s;
        }
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfsPos(v, u);
        }
    }
}

inline piii lca(int u, int v) {
    
    bool flag = 0;
    if (depth[u] > depth[v]) {
        swap(u, v);
        flag = 1;
    }
    int d = depth[v] - depth[u];
    int n = MAXL;
    while (d) {
        if (d - (1 << n) >= 0) {
            v = dp[v][n];
            d -= 1 << n;
        } else {
            n--;
        }
    }
    if (u == v) {
        return {{0, 0}, u};
    }
    
    for (int i = MAXL; i >= 0; i--) {
        if (dp[u][i] != -1 && (dp[u][i] != dp[v][i])) {
            u = dp[u][i], v = dp[v][i];
        }
    }
    if (flag) {
        swap(u, v);
    }
    return {{u, v}, dp[u][0]};
    
}

void addRoad(int a, int b) {
    a++, b++;
    adj[a].pb(b);
    adj[b].pb(a);
}

void buildFarms() {
    
    N = getN();
    Q = getQ();
    
    // lca preprocessing
    par[1] = -1;
    depth[1] = 0;
    dfs(1, -1);
    FILL(dp, -1);
    for (int i = 1; i <= N; i++) {
        dp[i][0] = par[i];
    }
    for (int j = 1; j <= MAXL; j++) {
        for (int i = 1; i <= N; i++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    
    dfsSz(1, -1);
    pos[1] = {1, 1};
    dfsPos(1, -1);
    for (int i = 1; i <= N; i++) {
        setFarmLocation(i - 1, pos[i].f, pos[i].s);
    }
    
}

void notifyFJ(int a, int b) {
    a++, b++;
    piii sol = lca(a, b);
    int p = sol.s;
    if (p == a || p == b) {
        if (p == b) {
            swap(b, a);
        }
        addBox(pos[a].f, pos[a].s, pos[b].f, pos[b].s);
    } else {
        addBox(pos[p].f, pos[p].s, pos[a].f, pos[a].s);
        addBox(pos[sol.f.s].f, pos[sol.f.s].s, pos[b].f, pos[b].s);
    }
}
