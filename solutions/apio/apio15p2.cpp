/*
 Solution to APIO '15 P2 - Jakarta Skyscrapers by Ava Pun
 Key concepts: graph theory, Dijkstra's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3F3F3F3F;
const int MAX = 3e4 + 5;

int N, M, A, B;
vector<int> arr[MAX];
int dist[MAX];
bool vis[MAX];

int dijk() {
    
    fill(dist, dist + N + 1, INF);
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    dist[A] = 0;
    pq.push({dist[A], A});
    
    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        int u = x.second;
        if (!vis[u]) {
            vis[u] = true;
            for (int i : arr[u]) {
                int v;
                for (int j = 1; u + (i * j) < N; j++) {
                    v = u + (i * j);
                    if (dist[u] + j < dist[v]) {
                        dist[v] = dist[u] + j;
                        pq.push({dist[v], v});
                    }
                }
                for (int j = -1; u + (i * j) >= 0; j--) {
                    v = u + (i * j);
                    if (dist[u] + abs(j) < dist[v]) {
                        dist[v] = dist[u] + abs(j);
                        pq.push({dist[v], v});
                    }
                }
            }
        }
    }
    
    return dist[B];
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        arr[a].push_back(b);
        if (i == 0) {
            A = a;
        } else if (i == 1) {
            B = a;
        }
    }
    
    int ans = dijk();
    printf("%d", ans == INF ? -1 : ans);
    
    return 0;
}
