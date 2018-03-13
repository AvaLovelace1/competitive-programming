/*
 ~ Floyd-Warshall All Pairs Shortest Paths Algorithm ~
 
 Finds all pairs shortest paths on a graph in V^3 time.
 This is slower than just running Dijkstra V times for a sparse graph, but optimal for dense graphs.
 Also, it's much faster to type (only 4 lines!~)
 Supports graphs with negative weight edges and detects negative weight cycles.
 Works best with the adjacency matrix representation of a graph.
 
 Time complexity: O(V^3)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 205;

int N, M;
int dist[MAX][MAX];

bool fw() {
    
    for (int k = 1; k <= N; k++) {
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++) {
                if (dist[u][k] != INF && dist[k][v] != INF) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }
    
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            if (dist[u][v] < 0) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    
    scanf("%d%d", &N, &M);
    
    memset(dist, INF, sizeof(dist));
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        dist[a][b] = dist[b][a] = d;
    }
    
    bool good = fw();
    if (!good) {
        printf("Negative weight cycle detected\n");
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
    
}
