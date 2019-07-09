/*
 Solution to Back to School '17: Hot and Cold by Ava Pun
 Key concepts: Euler tour, difference array, lowest common ancestor
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int MAXL = 17;

int N, S;
vi adj[MAX];
int dep[MAX], in[MAX], out[MAX];
int node[2 * MAX];
ll tour[2 * MAX], tour1[2 * MAX];
int par[18][MAX];
int cnt = 0;

void dfs(int u, int p) {
    in[u] = ++cnt;
    node[in[u]] = u;
    for (int v : adj[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            par[0][v] = u;
            dfs(v, u);
        }
    }
    out[u] = ++cnt;
    node[out[u]] = -u;
}

inline int ances(int u, int k) {
    for (int i = MAXL; i >= 0; i--) {
        if (k & (1 << i)) {
            u = par[i][u];
        }
    }
    return u;
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    u = ances(u, dep[u] - dep[v]);
    if (u == v) {
        return u;
    }
    for (int i = MAXL; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u], v = par[i][v];
        }
    }
    return par[0][u];
}

inline int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

inline void upd(int u, ll x, ll k) {
    if (u < 1) {
        return;
    }
    tour1[1] += x;
    if (u > 1) {
        tour[2] += k;
        tour[in[u] + 1] -= k;
    }
    tour1[in[u] + 1] -= x + k * dep[u];
}

inline void upd(int u, int v, ll x, ll k) {
    int p = lca(u, v);
    ll xu = x + k * dep[u];
    ll xv = x + k * (dep[u] - 2 * dep[p]);
    upd(u, xu, -k), upd(v, xv, k);
    upd(par[0][p], (-xu - xv) / 2, 0);
    upd(p, (-xu - xv) / 2, 0);
}

inline int closest(int u, int v, int t) {
    int p = lca(u, v), pu = lca(u, t), pv = lca(v, t);
    if (dep[pu] <= dep[p] && dep[pv] <= dep[p]) {
        return p;
    } else {
        return dep[pu] > dep[pv] ? pu : pv;
    }
}

int main() {

    scanf("%d%d", &N, &S);
    int a, b;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, -1);
    for (int i = 1; i <= MAXL; i++) {
        for (int j = 1; j <= N; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    int t;
    for (int i = 1; i <= S; i++) {
        scanf("%d%d%d", &a, &b, &t);
        int p = closest(a, b, t);
        upd(p, a, dist(p, t), 1);
        upd(p, b, dist(p, t), 1);
        upd(p, p, -dist(p, t), 0);
    }
    for (int i = 2; i <= 2 * N; i++) {
        tour[i] += tour[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        tour[in[i]] -= tour[out[i]];
        tour[out[i]] = 0;
    }
    for (int i = 1; i <= 2 * N; i++) {
        tour[i] += tour1[i];
    }
    for (int i = 2; i <= 2 * N; i++) {
        tour[i] += tour[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        printf("%lld", tour[in[i]] - tour[out[i]]);
        printf(i == N ? "\n" : " ");
    }
    
    return 0;
}
