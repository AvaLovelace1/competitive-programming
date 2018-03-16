/*
 Solution to UTS Open '15 #5 - Distribution Channel by Ava Pun
 Key concepts: graph theory, minimum spanning tree, heavy-light decomposition
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;
const int MAXE = 1e5 + 5;

int N, M;
vi adj[MAX];
pii endpts[MAXE];
int weight[MAXE], sorted[MAXE];
int par[MAX], depth[MAX], size[MAX], top[MAX], segPos[MAX];
int base[MAX], tree[2 * MAX];
int ranks[MAX];
int edgeCnt = 1;

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return false;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
    return true;
}

bool comp(int a, int b) {
    return weight[a] < weight[b];
}

int getNxt(int u, int e) {
    return endpts[e].f == u ? endpts[e].s : endpts[e].f;
}

void dfs(int u, int prev) {
    
    par[u] = prev;
    size[u] = 1;
    
    for (int e : adj[u]) {
        int v = getNxt(u, e);
        if (v != prev) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

void hld(int u, int e, int prev) {
    
    top[u] = prev;
    segPos[u] = edgeCnt;
    base[edgeCnt] = weight[e];
    edgeCnt++;
    
    int heavyC = -1, heavyE = -1;
    for (int i : adj[u]) {
        int v = getNxt(u, i);
        if (v != par[u] && (heavyC == -1 || size[v] > size[heavyC])) {
            heavyC = v;
            heavyE = i;
        }
    }
    
    if (heavyC != -1) {
        hld(heavyC, heavyE, top[u]);
    }
    
    for (int i : adj[u]) {
        int v = getNxt(u, i);
        if (v != par[u] && v != heavyC) {
            hld(v, i, v);
        }
    }
}

void build() {
    for (int i = 1; i <= N; i++) {
        tree[i + N - 1] = base[i];
    }
    for (int i = N - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

int querySeg(int l, int r) {
    l += N - 1, r += N - 1;
    int ans = -1;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = max(ans, tree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
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

int crawl(int u, int v) {
    int ans = -1;
    while (1) {
        if (top[u] == top[v]) {
            ans = max(ans, querySeg(segPos[v] + 1, segPos[u]));
            break;
        } else {
            ans = max(ans, querySeg(segPos[top[u]], segPos[u]));
            u = par[top[u]];
        }
    }
    return ans;
}

int query(int u, int v) {
    int a = lca(u, v);
    return max(crawl(u, a), crawl(v, a));
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        endpts[i] = {a, b};
        weight[i] = c;
        sorted[i] = i;
    }
    
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    sort(sorted + 1, sorted + M + 1, comp);
    int tot = 0, cnt = 0;
    for (int i = 1; i <= M && cnt < N - 1; i++) {
        int e = sorted[i];
        int u = endpts[e].f;
        int v = endpts[e].s;
        if (Union(u, v)) {
            tot += weight[e];
            cnt++;
            adj[u].pb(e), adj[v].pb(e);
        }
    }
    if (cnt != N - 1) {
        printf("-1\n");
        return 0;
    }
    
    dfs(1, 1);
    hld(1, 0, 1);
    build();
    
    int ans = INF;
    for (int i = 1; i <= M; i++) {
        int u = endpts[i].f;
        int v = endpts[i].s;
        int w = query(u, v);
        if (w != weight[i]) {
            ans = min(ans, weight[i] - w);
        }
    }
    printf("%d\n", ans == INF ? -1 : tot + ans);
    
    return 0;
    
}
