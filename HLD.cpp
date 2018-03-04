/*
 ~ HLD ~
 
 Supports efficient updates and queries on a tree by decomposing it into chains.
 Every time a path is traversed, it goes through max O(logV) chains, each of which takes O(logV) time to process an operation.
 Not a hard concept but annoying to implement.
 
 Time complexity:
 Preprocessing - O(V+E)
 Point update - O(log^2V) (can also do range update with lazy propagation)
 Range query - O(log^2V)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

const int ROOT = 1;
int N, Q;
vector<pii> adj[MAX];
int par[MAX], depth[MAX], size[MAX], top[MAX], segPos[MAX]; // node info
int weight[MAX], deeper[MAX]; // edge info
int base[MAX], tree[2 * MAX]; // segtree info
int edgeCnt = 1;

void dfs(int u, int prev) {
    
    par[u] = prev;
    size[u] = 1;
    
    for (pii e : adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v != prev) {
            depth[v] = depth[u] + 1;
            deeper[i] = v;
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
    for (pii e : adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v != par[u]) {
            if (heavyC == -1 || size[v] > size[heavyC]) {
                heavyC = v;
                heavyE = i;
            }
        }
    }
    
    if (heavyC != -1) {
        hld(heavyC, heavyE, top[u]);
    }
    
    for (pii e : adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v != par[u] && v != heavyC) {
            hld(v, i, v);
        }
    }
    
}

void buildSeg() {
    for (int i = 1; i <= N; i++) {
        tree[i + N - 1] = base[i];
    }
    for (int i = N - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

void updateSeg(int pos, int x) {
    pos += N - 1;
    tree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

int querySeg(int l, int r) {
    l += N - 1, r += N - 1;
    int ans = -INF;
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

void update(int e, int x) {
    updateSeg(segPos[deeper[e]], x);
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
    int ans = -INF;
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
    
    scanf("%d", &N);
    int a, b, d;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        weight[i] = d;
    }
    
    depth[ROOT] = 0;
    dfs(ROOT, ROOT);
    fill(top, top + N + 1, -1);
    hld(ROOT, 0, ROOT);
    buildSeg();
    
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d%d", &d, &a, &b);
        if (d == 1) {
            printf("Max edge from %d to %d: %d\n", a, b, query(a, b));
        } else {
            update(a, b);
        }
    }
    
    return 0;
}
