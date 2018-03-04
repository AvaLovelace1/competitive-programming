/*
 ~ Bellman-Ford Single Source Shortest Paths Algorithm ~
 
 Finds single source shortest paths on a graph.
 Supports graphs with negative weight edges and detects negative weight cycles.
 
 Time complexity: O(VE)
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
int dist[MAX];
int S, T;

int bf(int start, int end) {
    
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;
    
    for (int i = 1; i <= N - 1; i++) {
        for (int u = 1; u <= N; u++) {
            for (pii e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 1; u <= N; u++) {
        for (pii e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[u] + w < dist[v]) {
                return -1;
            }
        }
    }

    return dist[end];
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    
    scanf("%d%d", &S, &T);
    int dist = bf(S, T);
    if (dist == INF) {
        printf("No path from %d to %d\n", S, T);
    } else if (dist == -1) {
        printf("Negative weight cycle detected\n");
    } else {
        printf("Shortest path from %d to %d is %d\n", S, T, dist);
    }
    
    return 0;
    
}
