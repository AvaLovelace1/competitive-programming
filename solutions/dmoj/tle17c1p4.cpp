/*
 Solution to TLE '17 Contest 1 P4 - Tempest by Ava Pun
 Key concepts: graph theory, Dijkstra's
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int N, M, X, Y, Q;
vector<pii> adj[100001];
vector<piii> edges;
int distH[100001];
int distC[100001];
int reach[100001]; //0 hot 1 cold 2 both
bool visH[100001];
bool visC[100001];

void dijk() {
    
    fill(distH, distH + N + 1, INT_MAX);
    fill(distC, distC + N + 1, INT_MAX);
    fill(reach, reach + N + 1, -1);
    fill(visH, visH + N + 1, false);
    fill(visC, visC + N + 1, false);
    
    priority_queue< piii, vector<piii>, greater<piii> > pq;
    distH[X] = 0;
    distC[Y] = 0;
    pq.push({{0, X}, 0});
    pq.push({{0, Y}, 1});
    
    while (!pq.empty()) {
        
        piii x = pq.top();
        pq.pop();
        int u = x.first.second;
        int type = x.second;
        int *dist;
        int *dist2;
        bool *vis;
        
        dist = type == 0 ? distH : distC;
        dist2 = type == 0 ? distC : distH;
        vis = type == 0 ? visH : visC;
        
        if (reach[u] == -1 || (dist2[u] == dist[u] && reach[u] == !type)) {
            vis[u] = true;
            if (reach[u] == -1) {
                reach[u] = type;
            } else {
                reach[u] = 2;
            }
            for (pii e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if (!vis[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({{dist[v], v}, type});
                }
            }
        }
    }
    
}

int main() {
    
    scanf("%d%d%d%d", &N, &M, &X, &Y);
    
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edges.push_back({{a, b}, c});
    }
    
    dijk();
    
    scanf("%d", &Q);
    int f, l;
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &f, &l);
        if (f == 1) {
            if (reach[l] == 2) {
                printf("%d\n", distH[l]);
            } else {
                printf("-1\n");
            }
        } else {
            l--;
            int x = edges[l].first.first;
            int y = edges[l].first.second;
            int w = edges[l].second;
            double ans = 0;
            if ((reach[x] == 1 && reach[y] == 1) || (reach[x] == 0 && reach[y] == 0)) {
                ans = -1;
            } else if (reach[x] == 2 && reach[y] == 2) {
                ans = min(distH[x], distH[y]);
            } else if (reach[x] == 2) {
                if (reach[y] == 0) {
                    ans = distH[y] + w == distH[x] ? -1 : distH[x];
                } else {
                    ans = distC[y] + w == distC[x] ? -1 : distC[x];
                }
            } else if (reach[y] == 2) {
                if (reach[x] == 0) {
                    ans = distH[x] + w == distH[y] ? -1 : distH[y];
                } else {
                    ans = distC[x] + w == distC[y] ? -1 : distC[y];
                }
            } else if (reach[x] == 0 && reach[y] == 1) {
                int start = max(distH[x], distC[y]);
                w -= abs(distH[x] - distC[y]);
                ans = start + (w / 2.0);
            } else if (reach[x] == 1 && reach[y] == 0) {
                int start = max(distC[x], distH[y]);
                w -= abs(distC[x] - distH[y]);
                ans = start + (w / 2.0);
            }
            printf("%lf\n", ans);
        }
    }
    
    return 0;
    
}
