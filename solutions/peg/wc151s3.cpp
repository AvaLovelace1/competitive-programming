/*
 Solution to WC15 #1 - Contest Sites by Ava Pun
 Key concepts: graph theory, Dijkstra's, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;

const int MAX = 100001;
int N, M, K;
piii arr[MAX];
vector<pii> adj[MAX];
int dist1[MAX], dist2[MAX];
bool vis[MAX];

void dijk(int start, int dist[]) {
    
    fill(vis, vis + N + 1, 0);
    fill(dist, dist + N + 1, INF);
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));
    
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
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
    
}

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i].first.second);
        arr[i].second = i;
    }
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        adj[b].push_back(make_pair(a, d));
    }
    
    dijk(1, dist1);
    dijk(2, dist2);
    
    ll total = 0;
    
    for (int i = 1; i <= N; i++) {
        arr[i].first.first = dist1[i] - dist2[i];
    }
    
    for (int i = 1; i <= N; i++) {
        int n = arr[i].first.second;
        if (dist1[i] == INF) {
            if (dist2[i] == INF && n != 0) {
                printf("-1");
                return 0;
            }
            total += (ll) dist2[i] * n;
            K -= n;
            if (K < 0) {
                printf("-1");
                return 0;
            }
        }
    }
    
    sort(arr + 1, arr + N + 1, greater<piii>());
    
    for (int cnt = 1; cnt <= N; cnt++) {
        int i = arr[cnt].second;
        int n = arr[cnt].first.second;
        if (dist1[i] == INF && dist2[i] == INF && n != 0) {
            total = -1;
            break;
        } else if (dist2[i] == INF) {
            total += (ll) dist1[i] * n;
        } else if (dist1[i] != INF) {
            if (dist2[i] < dist1[i]) {
                int send = min(K, n);
                total += (ll) dist2[i] * send;
                K -= send;
                total += (ll) dist1[i] * (n - send);
            } else {
                total += (ll) dist1[i] * n;
            }
        }
    }
    
    printf("%lld", total);
    
    return 0;
}
