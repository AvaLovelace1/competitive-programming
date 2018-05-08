/*
 Solution to CCC '09 S4 - Shop and Ship by Ava Pun
 Key concepts: Dijkstra's
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3F3F3F3F;
int N, T, K, D;
int adj[5001][5001];
unordered_map<int, int> prices;
int dist[5001];
bool vis[5001];

int main() {
    
    scanf("%d%d", &N, &T);
    memset(adj, INF, sizeof(adj));
    int x, y, c;
    while (T--) {
        scanf("%d%d%d", &x, &y, &c);
        adj[x][y] = adj[y][x] = min(adj[x][y], c);
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &x, &c);
        prices[x] = c;
    }
    scanf("%d", &D);
    
    fill(dist, dist + N + 1, INF);
    dist[D] = 0;
    
    for (int i = 0; i < N; i++) {
        int u = 0;
        for (int i = 1; i <= N; i++) {
            if (!vis[i] && dist[i] < dist[u]) {
                u = i;
            }
        }
        vis[u] = true;
        for (int v = 1; v <= N; v++) {
            int d = dist[u] + adj[u][v];
            if (!vis[v] && d < dist[v]) {
                dist[v] = d;
            }
        }
    }
    
    int ans = INT_MAX;
    for (auto p : prices) {
        ans = min(ans, dist[p.first] + p.second);
    }
    
    printf("%d", ans);
    
    return 0;
}
