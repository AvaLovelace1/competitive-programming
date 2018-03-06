/*
 Solution to CCO Preparation Test 1 - Escape Maze by Ava Pun
 Key concepts: graph theory, articulation points, Tarjan's
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 405;

int N, M;
vector<int> adj[MAX];
int dfn[MAX], low[MAX];
bool art[MAX];
bool vis[MAX];
int cnt, compCnt;
stack<pii> st;
set<int> comps[MAX];

void findbcc(int u, int v) {
    if (st.empty()) {
        return;
    }
    while (!st.empty()) {
        pii e = st.top();
        st.pop();
        comps[compCnt].insert(e.first);
        comps[compCnt].insert(e.second);
        if (e.first == u && e.second == v) {
            break;
        }
    }
    compCnt++;
}

void tarj(int u, int prev) {
    
    low[u] = dfn[u] = cnt;
    cnt++;
    vis[u] = true;
    int children = 0;
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            st.push({u, v});
            children++;
            tarj(v, u);
            low[u] = min(low[u], low[v]);
            if ((prev == -1 && children > 1) || (prev != -1 && low[v] >= dfn[u])) {
                art[u] = true;
                findbcc(u, v);
            }
        } else if (v != prev && dfn[v] < low[u]) {
            low[u] = min(low[u], dfn[v]);
            st.push({u, v});
        }
    }
    
}

int main() {
    
    scanf("%d", &N);
    
    while (N) {
        
        cnt = 1;
        compCnt = 0;
        fill(dfn, dfn + MAX, 0);
        fill(low, low + MAX, 0);
        fill(vis, vis + MAX, 0);
        fill(art, art + MAX, 0);
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            comps[i].clear();
        }
        
        int a, b;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for (int i = 1; i <= 400; i++) {
            if (!vis[i]) {
                tarj(i, -1);
                findbcc(-1, -1);
            }
        }

        int minN = 0;
        ll ways = 1;
        for (int i = 0; i < compCnt; i++) {
            int nArts = 0;
            for (int j : comps[i]) {
                if (art[j]) {
                    nArts++;
                }
            }
            if (nArts == 0) {
                minN += 2;
                ways *= comps[i].size() * (comps[i].size() - 1) / 2;
            } else if (nArts == 1) {
                minN += 1;
                ways *= comps[i].size() - 1;
            }
        }
        printf("%d %lld\n", minN, ways);
        
        scanf("%d", &N);
    }
    
    return 0;
    
}
