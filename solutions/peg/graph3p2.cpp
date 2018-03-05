/*
 Solution to Shortest Path by Ava Pun
 Key concepts: graph theory, Bellman-Ford
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
const int INF = 0x3F3F3F3F;

int N, M;
vector<pii> adj[1005];
int dist[1005];

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b, c;
    while (M--) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
    }
    
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;
    
    for (int i = 1; i < N; i++) {
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
    
    printf("%d", dist[N]);
    
    return 0;
}
