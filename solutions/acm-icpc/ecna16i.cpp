/*
 Solution to ICPC ECNA 2016 I - Waif Until Dark by Ava Pun
 Key concepts: bipartite matching, maximum flow, Edmonds-Karp
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
typedef vector<pii> vii;
const int MAX = 105;
const int INF = 0x3F3F3F3F;

int N, M, P, S, T;
bool inCat[MAX];
int edges[2 * (MAX * MAX * 2 + MAX * 2)];
vii adj[3 * MAX];
int edgeCnt = 0;
pii par[3 * MAX];
bool vis[3 * MAX];
queue<int> q;

inline void addEdgeUtil(int u, int v, int w) {
    edgeCnt++;
    adj[u].pb({v, edgeCnt});
    edges[edgeCnt] = w;
}

inline void addEdge(int u, int v, int w) {
    addEdgeUtil(u, v, w);
    addEdgeUtil(v, u, 0);
}

inline bool bfs() {
    FILL(vis, 0);
    q.push(S);
    vis[S] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (pii e : adj[u]) {
            int v = e.f, w = edges[e.s];
            if (w && !vis[v]) {
                vis[v] = 1;
                par[v] = {u, e.s};
                q.push(v);
            }
        }
    }
    return vis[T];
}

int main() {
    
    scanf("%d%d%d", &N, &M, &P);
    S = N + M + P + 2;
    T = N + M + P + 3;
    int n, k;
    for (int i = 1; i <= N; i++) {
        addEdge(S, i, 1);
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &k);
            addEdge(i, N + k, 1);
        }
    }
    for (int i = 1; i <= P; i++) {
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &k);
            addEdge(N + k, N + M + i, 1);
            inCat[k] = 1;
        }
        scanf("%d", &k);
        addEdge(N + M + i, T, k);
    }
    for (int i = 1; i <= M; i++) {
        if (!inCat[i]) {
            addEdge(N + i, N + M + P + 1, 1);
        }
    }
    addEdge(N + M + P + 1, T, INF);
    
    int flow, maxFlow = 0;
    while (bfs()) {
        flow = INF;
        int u = T;
        while (u != S) {
            flow = min(flow, edges[par[u].s]);
            u = par[u].f;
        }
        u = T;
        while (u != S) {
            edges[par[u].s] -= flow;
            edges[par[u].s + 1] += flow;
            u = par[u].f;
        }
        maxFlow += flow;
    }
    printf("%d\n", maxFlow);
    
    return 0;
}
