/*
 Solution to Mock CCC '18 Contest 2 S4 - A Tree Problem by Ava Pun
 Key concepts: graph theory, DFS
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
const int MAX = 5e4 + 5;

int N;
vii adj[MAX];
bool bad[MAX], down[MAX], up[MAX];
bool all = 0;

void dfsBad(int u, int prev) {
    bad[u] = 1;
    for (pii e : adj[u]) {
        if (e.f != prev) {
            dfsBad(e.f, u);
        }
    }
}

void dfs(int u, int prev) {
    map<int, int> cols;
    for (pii e : adj[u]) {
        cols[e.s]++;
    }
    for (pii e : adj[u]) {
        int v = e.f, c = e.s;
        if (cols[c] > 1) {
            if (v != prev) {
                down[v] = 1;
            } else {
                up[u] = 1;
            }
            bad[v] = 1;
        }
        if (v != prev) {
            dfs(v, u);
        }
    }
    cols.clear();
}

bool dfsUp(int u, int prev) {
    bool ret = 0;
    int cnt = 0, tree = -1;
    for (pii e : adj[u]) {
        int v = e.f;
        if (v != prev) {
            bool b = dfsUp(v, u) | up[v];
            ret |= b;
            if (b) {
                tree = v;
                cnt++;
            }
        }
    }
    if (cnt > 1) {
        all = 1;
    } else if (cnt == 1) {
        bad[u] = 1;
        for (pii e : adj[u]) {
            int v = e.f;
            if (v != prev && v != tree) {
                down[v] = 1;
            }
        }
    }
    return ret;
}

void dfsDown(int u, int prev) {
    for (pii e : adj[u]) {
        int v = e.f;
        if (v != prev) {
            if (down[v]) {
                dfsBad(v, u);
            } else {
                dfsDown(v, u);
            }
        }
    }
}

int main() {
    
    scanf("%d", &N);
    int a, b, c;
    for (int i = 1; i < N; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    
    dfs(1, -1);
    dfsUp(1, -1);
    dfsDown(1, -1);
    if (all) {
        fill(bad + 1, bad + N + 1, 1);
    }
    
    printf("%d\n", N - accumulate(bad + 1, bad + N + 1, 0));
    for (int i = 1; i <= N; i++) {
        if (!bad[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
