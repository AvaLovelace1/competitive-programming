/*
 Solution to COCI '14 Contest 3 #5 Stogovi by Ava Pun
 Key concepts: lowest common ancestor, heavy-light decomposition
 */

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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 5;

int N;
vi adj[MAX];
int idx[MAX], par[MAX], size[MAX], top[MAX], depth[MAX];
pii quers[MAX];
int ans[MAX];

void dfs(int u) {
    size[u] = 1;
    for (int v : adj[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
        size[u] += size[v];
    }
}

void hld(int u, int prev) {
    
    top[u] = prev;
    int heavyC = -1;
    for (int v : adj[u]) {
        if (heavyC == -1 || size[v] > size[heavyC]) {
            heavyC = v;
        }
    }
    if (heavyC != -1) {
        hld(heavyC, top[u]);
    }
    for (int v : adj[u]) {
        if (v != heavyC) {
            hld(v, v);
        }
    }
    
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }
        u = par[top[u]];
    }
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    return v;
}

int main() {
    
    scanf("%d", &N);
    FILL(ans, -1);
    for (int i = 1; i <= N; i++) {
        quers[i] = {-1, -1};
    }
    
    char c;
    int v, w;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        if (c == 'a') {
            scanf("%d", &v);
            idx[i] = i;
            adj[idx[v]].pb(idx[i]);
            par[idx[i]] = idx[v];
        } else if (c == 'b') {
            scanf("%d", &v);
            idx[i] = par[idx[v]];
            ans[i] = idx[v];
        } else {
            scanf("%d%d", &v, &w);
            quers[i] = {idx[v], idx[w]};
            idx[i] = idx[v];
        }
    }
    
    depth[0] = 0;
    dfs(0);
    hld(0, 0);

    for (int i = 1; i <= N; i++) {
        if (quers[i].f != -1 || quers[i].s != -1) {
            ans[i] = depth[lca(quers[i].f, quers[i].s)];
        }
        if (ans[i] != -1) {
            printf("%d\n", ans[i]);
        }
    }
    
    return 0;
}
