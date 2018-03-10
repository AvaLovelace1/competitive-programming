/*
 Solution to Summer Institute '17 Contest 3 P4 - Customs by Ava Pun
 Key concepts: graph theory, Tarjan's, cacti
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e4 + 5;

int N, M;
vector<int> adj[MAX];
int low[MAX], dfn[MAX];
bool vis[MAX];
int cnt = 1, compCnt = 0;
stack<pii> st;
pii comps[MAX];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}

void findbcc(int u, int v) {
    int num = 0;
    unordered_set<int> s;
    while (!st.empty()) {
        pii e = st.top();
        s.insert(e.first);
        s.insert(e.second);
        st.pop();
        num++;
        if (e.first == u && e.second == v) {
            break;
        }
    }
    if (num != 0) {
        comps[compCnt] = {num, (int) s.size()};
        compCnt++;
    }
}

void tarj(int u, int prev) {
    
    low[u] = dfn[u] = cnt;
    cnt++;
    vis[u] = true;
    int children = 0;
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            children++;
            st.push({u, v});
            tarj(v, u);
            low[u] = min(low[u], low[v]);
            if ((prev == -1 && children > 1) || (prev != -1 && low[v] >= dfn[u])) {
                findbcc(u, v);
            }
        } else if (v != prev && dfn[v] < low[u]) {
            low[u] = dfn[v];
            st.push({u, v});
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vis[1] = true;
    dfs(1);
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            printf("safe");
            return 0;
        }
    }
    
    fill(vis, vis + N + 1, 0);
    tarj(1, -1);
    findbcc(-1, -1);
    
    ll ans = 1;
    for (int i = 0; i < compCnt; i++) {
        pii p = comps[i];
        if (p.first != 1 && p.first != p.second) {
            printf("safe");
            return 0;
        }
        ans *= p.first;
        ans %= MOD;
    }
    
    printf("%lld", ans);
    
    return 0;
}
