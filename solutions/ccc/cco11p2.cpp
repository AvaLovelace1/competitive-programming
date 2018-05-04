/*
 Solution to CCO '11 P2 - Vampire Tunnels by Ava Pun
 Key concepts: graph theory, Dijkstra's
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<piii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1605;

int N, M, K;
vii adj[MAX];
int dist[MAX];

int main() {
    
    scanf("%d%d%d", &K, &N, &M);
    int a, b, d, u;
    while (M--) {
        scanf("%d%d%d%d", &a, &b, &d, &u);
        adj[a].pb({b, {d, u}});
        adj[b].pb({a, {d, u}});
    }
    
    FILL(dist, INF);
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dist[0] = 0;
    pq.push({0, {0, 0}});
    
    while (!pq.empty()) {
        piii x = pq.top();
        pq.pop();
        int k = x.f, u = x.s.f, d = x.s.s;
        dist[u] = min(dist[u], d);
        for (piii e : adj[u]) {
            int v = e.f, w = e.s.f, t = e.s.s;
            int k1 = k + w * t;
            if (k1 <= K && dist[v] > d + w) {
                pq.push({k1, {v, d + w}});
            }
        }
    }
    
    printf("%d\n", dist[N - 1] == INF ? -1 : dist[N - 1]);
    
    return 0;
}
