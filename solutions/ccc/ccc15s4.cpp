/*
 Solution to CCC '15 S4 - Convex Hull by Ava Pun
 Key concepts: Dijkstra's
 */


#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int K, N, M, A, B;
vector< pair<int, pii> > adj[2001];
int dist[2001][201];

int dijk() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    priority_queue< pair<pii, int>, vector< pair<pii, int> >, greater< pair<pii, int> > > pq;
    pq.push({{0, 0}, A});
    dist[A][0] = 0;
    while (!pq.empty()) {
        pair<pii, int> x = pq.top();
        pq.pop();
        int h0 = x.first.second;
        int u = x.second;
        for (pair<int, pii> n : adj[u]) {
            int v = n.first;
            int t = n.second.first;
            int h = n.second.second;
            if (dist[u][h0] + t < dist[v][h + h0] && h + h0 < K) {
                dist[v][h + h0] = dist[u][h0] + t;
                pq.push({{dist[v][h + h0], h + h0}, v});
            }
        }
    }
    int minN = INT_MAX;
    for (int i = 0; i < K; i++) {
        minN = min(minN, dist[B][i]);
    }
    return minN;
}

int main() {
    
    scanf("%d%d%d", &K, &N, &M);
    int a, b, t, h;
    while (M--) {
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adj[a].push_back({b, {t, h}});
        adj[b].push_back({a, {t, h}});
    }
    scanf("%d%d", &A, &B);
    int ans = dijk();
    printf("%d", ans == INT_MAX ? -1 : ans);
    
    return 0;
}
