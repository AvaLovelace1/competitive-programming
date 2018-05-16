/*
 Solution to CCO '14 P2 - King Gruff by Ava Pun
 Key concepts: Dijkstra's
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3F3F3F3F;
const int MAX = 1e5 + 5;

int N, M, A, B, Q;
vi adj[MAX], adjrev[MAX];
int startp[MAX], endp[MAX], len[MAX], cost[MAX];
int dist[MAX], distrev[MAX];
bool vis[MAX];
map<int, int> mp;
pii quers[MAX];
int ans[MAX];

void dijk(int S, vi adj[], int endp[], int dist[]) {
    
    fill(dist + 1, dist + N + 1, INF);
    FILL(vis, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[S] = 0;
    pq.push({0, S});
    
    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        int u = x.s;
        if (!vis[u]) {
            vis[u] = true;
            for (int e : adj[u]) {
                int v = endp[e];
                int w = len[e];
                if (!vis[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
}

int main() {
    
    scanf("%d%d%d%d", &N, &M, &A, &B);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d%d", &startp[i], &endp[i], &len[i], &cost[i]);
        adj[startp[i]].pb(i);
        adjrev[endp[i]].pb(i);
    }
    
    dijk(A, adj, endp, dist);
    dijk(B, adjrev, startp, distrev);
    
    for (int i = 1; i <= M; i++) {
        int u = startp[i], v = endp[i];
        int d = dist[u] + len[i] + distrev[v];
        mp[d] += cost[i];
    }
    
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &quers[i].f);
        quers[i].s = i;
    }
    sort(quers + 1, quers + Q + 1);
    
    auto itr = mp.begin();
    int tot = 0;
    for (int i = 1; i <= Q; i++) {
        int d = quers[i].f, idx = quers[i].s;
        while (itr != mp.end() && (*itr).f <= d) {
            tot += (*itr).s;
            itr++;
        }
        ans[idx] = tot;
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}


