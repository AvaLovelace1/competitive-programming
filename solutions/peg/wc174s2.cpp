/*
 Solution to WC17 #4 - Strange Travels by Ava Pun
 Key concepts: graph theory, BFS
 */
 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, K;
vi adj[MAX], rev[MAX];
int dist1[MAX], dist2[MAX];
bool vis[MAX];

void bfs(int start, int dist[], vi adj[]) {
    
    fill(vis, vis + N + 1, false);
    fill(dist, dist + N + 1, INF);
    
    queue<int> q;
    q.push(start);
    vis[start] = true;
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        rev[b].pb(a);
    }
    bfs(1, dist1, adj);
    bfs(1, dist2, rev);
    
    ll ans = 0;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &a);
        if (dist1[a] != INF && dist2[a] != INF && ans != -1) {
            ans = ans + dist1[a] + dist2[a];
        } else {
            ans = -1;
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
