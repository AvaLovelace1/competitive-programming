/*
 Solution to King Graff's Trip by Ava Pun
 Key concepts: Dijkstra's, binary search
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<pair<int, ll>> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 1e4 + 5;

int N, M, X, Y, S;
ll L;
int shrines[105];
vii adj0[MAX], meta[MAX];
ll dist[MAX];
bool vis[MAX];

inline void dijk(int x, ll maxT, vii adj[], bool vis[], ll dist[]) {
    fill(vis, vis + N + 1, 0);
    fill(dist, dist + N + 1, INFL);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, x});
    dist[x] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().s;
        pq.pop();
        if (!vis[u]) {
            vis[u] = 1;
            for (auto e : adj[u]) {
                int v = e.f;
                ll w = e.s;
                if (w <= maxT && !vis[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}

int main() {
    
    scanf("%d%d%d%d%lld", &N, &M, &X, &Y, &L);
    int a, b, t;
    while (M--) {
        scanf("%d%d%d", &a, &b, &t);
        adj0[a].pb({b, t});
    }
    scanf("%d", &S);
    for (int i = 1; i <= S; i++) {
        scanf("%d", &shrines[i]);
    }
    shrines[S + 1] = X;
    shrines[S + 2] = Y;
    S += 2;
    
    for (int i = 1; i <= S; i++) {
        dijk(shrines[i], INFL, adj0, vis, dist);
        for (int j = 1; j <= S; j++) {
            if (i != j && dist[shrines[j]] != INFL) {
                meta[shrines[i]].pb({shrines[j], dist[shrines[j]]});
            }
        }
    }
    
    ll lo = 0, hi = 1e14 + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        dijk(X, mid, meta, vis, dist);
        if (dist[Y] <= L) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    printf("%lld\n", lo > 1e14 ? -1 : lo);
    
    return 0;
}
