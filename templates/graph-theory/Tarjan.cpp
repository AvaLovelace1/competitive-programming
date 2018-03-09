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
pii edges[MAXE];
int dfn[MAX], low[MAX];
bool vis[MAX], visE[MAXE];
bool art[MAX], bridge[MAXE];
stack<int> st;
int cnt = 1;

void findbcc(int e) {
    while (!st.empty()) {
        int x = st.top();
        printf("{%d, %d} ", edges[x].first, edges[x].second);
        st.pop();
        if (x == e) {
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
    
    for (int e : adj[u]) {
        
        if (!visE[e]) {
            
            visE[e] = true;
            st.push(e);
            int v = edges[e].first == u ? edges[e].second : edges[e].first;
            
            if (!vis[v]) {
                children++;
                tarj(v, u);
                low[u] = min(low[u], low[v]);
                if ((prev == -1 && children > 1) || (prev != -1 && low[v] >= dfn[u])) {
                    art[u] = true;
                    findbcc(e);
                }
                if (low[v] > dfn[u]) {
                    bridge[e] = true;
                }
            } else if (v != prev) {
                low[u] = min(low[u], dfn[v]);
            }
            
        }
    }
    
}

void findscc(int u) {
    while (!st.empty()) {
        int v = st.top();
        st.pop();
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
    st.push(u);
    
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
            adj[a].push_back(i);
            adj[b].push_back(i);
            edges[i] = {a, b};
        }
        
        printf("Biconnected components:\n");
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                tarj(i, -1);
                findbcc(-1);
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
        for (int i = 1; i <= M; i++) {
            if (bridge[i]) {
                printf("{%d, %d} ", edges[i].first, edges[i].second);
            }
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
