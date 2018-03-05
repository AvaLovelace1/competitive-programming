/*
 Solution to DMOPC '14 Exam Time P4 - Exam Delay by Ava Pun
 Key concepts: graph theory, Dijkstra's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MAX = 1005;

int V, E;
vector<pii> adj[MAX];
bool vis[MAX];
double dist[MAX];
int edges[MAX];
pii parent[MAX];

struct comp {
    bool operator()(const piii& a, const piii& b) {
        if (abs(a.first.first - b.first.first) < 1e-9) {
            return a.first.second > b.first.second;
        } else {
            return a.first.first > b.first.first;
        }
    }
};

int main() {
    
    scanf("%d%d", &V, &E);
    int m, n, d, s;
    while (E--) {
        scanf("%d%d%d%d", &m, &n, &d, &s);
        double dist = (double) d / s * 60;
        adj[m].push_back({dist, n});
        adj[n].push_back({dist, m});
    }
    
    fill(dist, dist + V + 1, INF);
    fill(edges, edges + V + 1, INF);
    dist[1] = edges[1] = 0;
    parent[1] = {0, 1};
    
    priority_queue< piii, vector<piii>, comp > pq;
    pq.push({{0, 0}, 1});
    
    while (!pq.empty()) {
        piii x = pq.top();
        pq.pop();
        int u = x.second;
        if (!vis[u]) {
            vis[u] = true;
            for (pii e : adj[u]) {
                int v = e.second;
                double w = e.first;
                if (!vis[v] && ((dist[u] + w - dist[v] < -1e-9) || ((abs(dist[u] + w - dist[v]) < 1e-9) && edges[u] + 1 < edges[v]))) {
                    dist[v] = dist[u] + w;
                    edges[v] = edges[u] + 1;
                    parent[v] = {w, u};
                    pq.push({{dist[v], edges[v]}, v});
                }
            }
        }
    }
    
    int x = V;
    double total = 0;
    while (parent[x].second != x) {
        total += parent[x].first * 4 / 3;
        x = parent[x].second;
    }
    
    printf("%d\n%d", edges[V], (int) round(total - dist[V]));
    
    return 0;
}
