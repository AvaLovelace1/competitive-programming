/*
 Solution to WC18 #4 - Dance Royale by Ava Pun
 Key concepts: graph theory, DFS, successor graph
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 5;

int N, M;
int D[MAX], L[MAX], nPpl[MAX];
vi rev[MAX];
int dist[MAX], cycle[MAX], par[MAX];
unordered_map<int, int> mp;

void dfs(int u) {
    if (D[u] == 0) {
        cycle[u] = 0;
        par[u] = u;
    } else if (cycle[D[u]] != -1) {
        cycle[u] = cycle[D[u]];
        par[u] = par[D[u]];
    } else if (dist[D[u]] == INF) {
        dist[D[u]] = dist[u] + 1;
        dfs(D[u]);
        cycle[u] = cycle[D[u]];
        par[u] = par[D[u]];
    } else {
        cycle[u] = dist[u] + 1 - dist[D[u]];
        par[u] = u;
    }
}

void dfsRev(int u) {
    mp[cycle[u] == 0 ? dist[u] : dist[u] % cycle[u]] += nPpl[u];
    for (int v : rev[u]) { 
        if (dist[v] == INF) {
            dist[v] = dist[u] + 1;
            dfsRev(v);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &D[i]);
        rev[D[i]].pb(i);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d", &L[i]);
        nPpl[L[i]]++;
    }
    
    FILL(dist, INF);
    FILL(cycle, -1);
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {
            dist[i] = 0;
            dfs(i);
        }
    }

    ll ans = 0;
    FILL(dist, INF);
    for (int i = 1; i <= N; i++) {
        if (dist[par[i]] == INF) {
            mp.clear();
            dist[par[i]] = 0;
            dfsRev(par[i]);
            for (auto p : mp) {
                ans += (ll) p.s * (p.s - 1) / 2;
            }
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
