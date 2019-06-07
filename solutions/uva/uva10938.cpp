/*
 Solution to 10938 - Flea circus by Ava Pun
 Key concepts: lowest common ancestor, binary lifting
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 5005;

int N, Q;
vi adj[MAX];
int dep[MAX], par[15][MAX];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            par[0][v] = u;
            dfs(v, u);
        }
    }
}

inline int ances(int u, int k) {
    for (int i = 13; i >= 0; i--) {
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
    for (int i = 13; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u], v = par[i][v];
        }
    }
    return par[0][u];
}

inline pii solve(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int a = lca(u, v);
    int dist = dep[u] + dep[v] - 2 * dep[a];
    u = ances(u, dist / 2);
    if (!(dist & 1)) {
        v = -1;
    } else {
        v = ances(u, 1);
    }
    if (u > v) {
        swap(u, v);
    }
    return {u, v};
}

int main() {

    scanf("%d", &N);
    while (N) {
        FILL(par, 0);
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        int a, b;
        for (int i = 1; i <= N - 1; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dep[1] = 0;
        dfs(1, -1);
        for (int i = 1; i <= 13; i++) {
            for (int j = 1; j <= N; j++) {
                par[i][j] = par[i - 1][par[i - 1][j]];
            }
        }
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            scanf("%d%d", &a, &b);
            pii ans = solve(a, b);
            if (ans.f == -1) {
                printf("The fleas meet at %d.\n", ans.s);
            } else {
                printf("The fleas jump forever between %d and %d.\n", ans.f, ans.s);
            }
        }
        scanf("%d", &N);
    }

    return 0;
}
