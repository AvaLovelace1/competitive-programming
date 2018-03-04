/*
 ~ Prim's Minimum Spanning Tree Algorithm ~
 
 Finds the minimum spanning tree of a graph. Classical implementation is optimal for dense graphs.
 The same thing as Dijkstra's, basically.
 
 Time complexity:
 Classical - O(V^2) (optimal for dense graphs)
 Optimized - O((V+E)logV) (binary heap), O(E+VlogV) (Fibonacci heap)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

int N, M;
vector<pii> adj[MAX];
int adj1[MAX][MAX];
int dist[MAX];
bool vis[MAX];

int prim() {
    
    fill(vis, vis + N + 1, false);
    fill(dist, dist + N + 1, INF);
    
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    
    int ans = 0;
    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        int u = x.second;
        if (!vis[u]) {
            vis[u] = true;
            ans += x.first;
            for (pii e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if (!vis[v] && w < dist[v]) {
                    dist[v] = w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    return ans;
}

int primClassic() {
    
    fill(vis, vis + N + 1, false);
    fill(dist, dist + N + 1, INF);
    
    dist[1] = 0;
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int u = 0;
        for (int j = 1; j <= N; j++) {
            if (!vis[j] && dist[j] < dist[u]) {
                u = j;
            }
        }
        vis[u] = true;
        ans += dist[u];
        for (int v = 1; v <= N; v++) {
            int w = adj1[u][v];
            if (!vis[v] && w < dist[v]) {
                dist[v] = w;
            }
        }
    }
    
    return ans;
}

int main() {
    
    memset(adj1, INF, sizeof(adj1));
    
    scanf("%d%d", &N, &M);
    int a, b, d;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
        adj1[a][b] = adj1[b][a] = d;
    }
    
    printf("Weight of minimum spanning tree:\n");
    printf("Optimized: %d\n", prim());
    printf("Classical: %d\n", primClassic());
    
    return 0;
    
}
