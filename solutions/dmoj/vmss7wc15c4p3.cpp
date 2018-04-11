/*
 Solution to VM7WC '15 #4 Gold - Chain Rule by Ava Pun
 Key concepts: graph theory, Dijkstra's
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 0x3F3F3F3F;
int N, M;
vector<pii> adj[100001];
int dist1[100001], dist2[100001];
bool vis[100001];

void dijk(int start, int dist[]) {
    fill(vis, vis + N, 0);
    fill(dist, dist + N, INF);
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
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b, t;
    while (M--) {
        scanf("%d%d%d", &a, &b, &t);
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    
    dijk(0, dist1);
    dijk(N - 1, dist2);
    
    int maxN = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (dist1[i] != INF && dist2[i] != INF) {
            maxN = max(maxN, dist1[i] + dist2[i]);
        }
    }
    
    printf("%d", maxN);
    
    return 0;
    
}
