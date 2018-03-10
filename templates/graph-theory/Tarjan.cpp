/*
 ~ Tarjan's Algorithm ~
 
 DFS-based algorithm for finding strongly connected components in a directed graph,
 and bi-connected (2-vertex connected) components, articulation points, & bridges in an undirected graph.
 (To find 2-edge-connected components, simply remove all bridges and do a DFS.)
 
 Time complexity: O(V+E)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int MAXE = 1e6 + 5;

int N, M;
vector<int> adj[MAX];
int dfn[MAX], low[MAX];
bool vis[MAX];
bool art[MAX];
pii bridges[MAXE];
stack<pii> st;
stack<int> st1;
int cnt = 1, bridgeCnt = 0;

void findbcc(int u, int v) {
    while (!st.empty()) {
        pii e = st.top();
        printf("{%d, %d} ", e.first, e.second);
        st.pop();
        if (e.first == u && e.second == v) {
            printf("\n");
            return;
        }
    }
}

void tarj(int u, int prev) {
    
    low[u] = dfn[u] = cnt;
    vis[u] = true;
    cnt++;
    int children = 0;
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            children++;
            st.push({u, v});
            tarj(v, u);
            low[u] = min(low[u], low[v]);
            if ((prev == -1 && children > 1) || (prev != -1 && low[v] >= dfn[u])) {
                art[u] = true;
                findbcc(u, v);
            }
            if (low[v] > dfn[u]) {
                bridges[bridgeCnt] = {u, v};
                bridgeCnt++;
            }
        } else if (v != prev && dfn[v] < low[u]) {
            low[u] = dfn[v];
            st.push({u, v});
        }
    }
}

void findscc(int u) {
    while (!st1.empty()) {
        int v = st1.top();
        st1.pop();
        dfn[v] = INF;
        printf("%d ", v);
        if (v == u) {
            printf("\n");
            return;
        }
    }
}

void tarjscc(int u) {
    
    dfn[u] = low[u] = cnt;
    vis[u] = true;
    cnt++;
    st1.push(u);
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            tarjscc(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
    if (dfn[u] == low[u]) {
        findscc(u);
    }
    
}

int main() {
    
    char c;
    scanf(" %c%d%d", &c, &N, &M);
    
    if (c == 'U') {
        
        int a, b;
        for (int i = 1; i <= M; i++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        printf("Biconnected components:\n");
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                tarj(i, -1);
                findbcc(-1, -1);
            }
        }
        printf("\n\n");
        
        printf("Articulation points: ");
        for (int i = 1; i <= N; i++) {
            if (art[i]) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
        printf("Bridges: ");
        for (int i = 0; i < bridgeCnt; i++) {
            printf("{%d, %d} ", bridges[i].first, bridges[i].second);
        }
        printf("\n\n");
        
    } else if (c == 'D') {
        
        int a, b;
        while (M--) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }
        
        printf("Strongly connected components:\n");
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                vis[i] = true;
                tarjscc(i);
                findscc(-1);
            }
        }
        
    }
    
    return 0;
    
}
