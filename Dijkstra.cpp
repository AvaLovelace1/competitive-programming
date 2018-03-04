/*
 ~ Dijkstra's Single Source Shortest Paths Algorithm ~
 
 Finds single source shortest paths on a graph with no negative weight edges.
 Sort of like a modified BFS.
 
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
int S, T;

int dijk(int start, int end) {
    
    fill(vis, vis + N + 1, false);
    fill(dist, dist + N + 1, INF);
    
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    dist[start] = 0;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        int u = x.second;
        if (!vis[u]) {
            vis[u] = true;
            for (pii e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if (!vis[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    return dist[end];
}

int dijkClassic(int start, int end) {
    
    fill(vis, vis + N + 1, false);
    fill(dist, dist + N + 1, INF);
    
    dist[start] = 0;
    
    for (int i = 1; i <= N; i++) {
        int u = 0;
        for (int j = 1; j <= N; j++) {
            if (!vis[j] && dist[j] < dist[u]) {
                u = j;
            }
        }
        vis[u] = true;
        for (int v = 1; v <= N; v++) {
            int w = adj1[u][v];
            if (!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    return dist[end];
}

int main() {
    
    memset(adj1, INF, sizeof(adj1));
    
    scanf("%d%d", &N, &M);
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
        adj1[a][b] = adj1[b][a] = d;
    }
    
    scanf("%d%d", &S, &T);
    int dist1 = dijk(S, T), dist2 = dijkClassic(S, T);
    if (dist1 == INF) {
        printf("No path from %d to %d\n", S, T);
    } else {
        printf("Optimized: Shortest path from %d to %d is %d\n", S, T, dist1);
        printf("Classical: Shortest path from %d to %d is %d\n", S, T, dist2);
    }
    
    return 0;
    
}
