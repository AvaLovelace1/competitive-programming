/*
 Solution to TLE '16 Contest 8 P5 - Prom Night by Ava Pun
 Key concepts: bipartite matching, Ford-Fulkerson's
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
int MAX;
bool adj[205][205];
int parent[205];
bool vis[205];
unordered_set<int> s;

void dfsUtil(int u) {
    for (int v = 0; v <= MAX; v++) {
        if (!vis[v] && adj[u][v]) {
            vis[v] = true;
            parent[v] = u;
            dfsUtil(v);
        }
    }
}

bool dfs() {
    fill(vis, vis + MAX + 1, 0);
    parent[0] = 0;
    vis[0] = true;
    dfsUtil(0);
    return vis[MAX];
}

int main() {
    
    scanf("%d%d", &N, &M);
    MAX = N + M + 1;
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        s.insert(n);
    }
    for (int i = 2; i <= N; i++) {
        adj[0][i] = 1;
        scanf("%d", &t);
        while (t--) {
            scanf("%d", &n);
            if (s.find(n) != s.end()) {
                adj[i][n + N] = 1;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        adj[i + N][MAX] = 1;
    }
    
    int maxFlow = 0;
    while (dfs()) {
        for (int v = MAX; v != 0; v = parent[v]) {
            int u = parent[v];
            adj[u][v] = 0;
            adj[v][u] = 1;
        }
        maxFlow++;
    }
    
    printf("%d", (int) s.size() - maxFlow);
    
    return 0;
}
