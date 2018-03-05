/*
 Solution to DMOPC '15 Contest 3 P4 - Contagion by Ava Pun
 Key concepts: graph theory, classical Dijkstra's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, int> pii;
const int MAX = 3005;

int N, X, Q;
pair<int, int> vals[MAX];
ll adj[MAX][MAX];
ll dist[MAX];
bool vis[MAX];

void dijk() {
    
    fill(dist, dist + N + 1, INT64_MAX);
    fill(vis, vis + N + 1, false);
    dist[X] = 0;
    
    for (int count = 1; count <= N; count++) {
        int u = 0;
        for (int i = 1; i <= N; i++) {
            if (!vis[i] && dist[i] < dist[u]) {
                u = i;
            }
        }
        vis[u] = true;
        for (int v = 1; v <= N; v++) {
            ll w = adj[u][v];
            if (!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
}

int main() {
    
    scanf("%d", &N);
    int a, b;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &a, &b);
        vals[i] = {a, b};
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            a = abs(vals[i].first - vals[j].first);
            b = abs(vals[i].second - vals[j].second);
            ll w = (ll) a * a + (ll) b * b;
            adj[i][j] = w;
            adj[j][i] = w;;
        }
    }
    
    scanf("%d%d", &X, &Q);
    
    dijk();
    
    sort(dist, dist + N + 1);
    
    ll q;
    while (Q--) {
        scanf("%lld", &q);
        auto itr = upper_bound(dist, dist + N + 1, q);
        printf("%ld\n", itr - dist);
    }
    
    return 0;
}
