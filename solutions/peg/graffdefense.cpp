/*
 Solution to King Graff's Defense by Ava Pun
 Key concepts: graph theory, bridges, Tarjan's
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MAX = 1e6 + 5;

int N, M;
vector<int> adj[MAX];
int low[MAX], dfn[MAX], parent[MAX];
bool vis[MAX];
int cnt = 1;

void tarj(int u) {
    
    low[u] = dfn[u] = cnt;
    cnt++;
    vis[u] = true;
    
    for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) {
        int v = *itr;
        if (!vis[v]) {
            parent[v] = u;
            tarj(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                adj[u].erase(itr);
                adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
                itr--;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
}

int dfs(int u) {
    int ans = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            ans += dfs(v);
        }
    }
    return ans;
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    tarj(1);
    fill(vis, vis + N + 1, 0);
    
    ll total = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            int sz = dfs(i);
            total += (ll) sz * (N - sz);
        }
    }
    
    printf("%.5lf", total / 2.0 / ((ll) N * (N - 1) / 2));
    
    return 0;
}
