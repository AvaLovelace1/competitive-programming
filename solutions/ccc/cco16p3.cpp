/*
 Solution to CCO '16 P3 - Legends by Ava Pun
 Key concepts: graph theory, Tarjan's
 */
 
// fox subtask can go die

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int S, T, N, M;
vector<int> adj[MAX];
int dfn[MAX], low[MAX];
bool vis[MAX];
int cnt = 1, compCnt = 0;
stack<pii> st;
map<int, int> comps[MAX];

void findbcc(int u, int v) {
    if (st.empty()) {
        return;
    }
    while (!st.empty()) {
        pii e = st.top();
        st.pop();
        comps[compCnt][e.first]++;
        comps[compCnt][e.second]++;
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
                findbcc(u, v);
            }
            
        } else if (v != prev && dfn[v] < dfn[u]) {
            low[u] = min(low[u], dfn[v]);
            st.push({u, v});
        }
    }
    
}

void tarj() {
    cnt = 1, compCnt = 0;
    fill(vis, vis + N + 1, 0);
    fill(dfn, dfn + N + 1, 0);
    fill(low, low + N + 1, 0);
    while (!st.empty()) {
        st.pop();
    }
    for (int i = 0; i <= N; i++) {
        comps[i].clear();
    }
    tarj(1, -1);
    findbcc(-1, -1);
}

int cntEdges(int i) {
    int edges = 0;
    for (pii p : comps[i]) {
        for (int v : adj[p.first]) {
            if (comps[i].find(v) != comps[i].end()) {
                edges++;
            }
        }
    }
    edges /= 2;
    return edges;
}

bool cntDeg1(int i) {
    int num = 0;
    for (pii p : comps[i]) {
        if (adj[p.first].size() >= 3) {
            num++;
        }
    }
    return num >= 2;
}

bool cntDeg2(int i) {
    for (pii p : comps[i]) {
        if (adj[p.first].size() > p.second) {
            return true;
        }
    }
    return false;
}

int main() {
    
    scanf("%d%d", &S, &T);
    
    int a, b;
    while (T--) {
        
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 1; i <= M; i++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        bool found = false;
        
        if (S == 1) {
            
            tarj();
            for (int i = 0; i < compCnt && !found; i++) {
                int edges = cntEdges(i);
                if (edges > comps[i].size()) {
                    found = true;
                }
            }
            
        } else if (S == 2) {
            
            found = M >= N;
            
        } else if (S == 3) {
            
            tarj();
            for (int i = 0; i < compCnt && !found; i++) {
                if (comps[i].size() >= 4) {
                    found = true;
                }
            }
            
        } else if (S == 4) {
            
            for (int i = 1; i <= N && !found; i++) {
                if (adj[i].size() >= 3) {
                    found = true;
                }
            }
            
        } else if (S == 5) {
            
            tarj();
            for (int i = 0; i < compCnt && !found; i++) {
                
                if (comps[i].size() > 4) {
                    
                    bool special = false;
                    
                    int idx = 0;
                    int nodes[2];
                    for (pii p : comps[i]) {
                        if (p.second > 2) {
                            if (idx >= 2) {
                                special = false;
                            } else {
                                nodes[idx] = p.first;
                                idx++;
                                special = idx == 2;
                            }
                        }
                    }
                    
                    if (special) {
                        for (pii p : comps[i]) {
                            int u = p.first;
                            for (int v : adj[u]) {
                                if (comps[i].find(v) != comps[i].end() &&
                                    (u != nodes[0] && u != nodes[1] && v != nodes[0] && v != nodes[1])) {
                                    special = false;
                                }
                            }
                        }
                    }
                    
                    if (special) {
                        found = cntEdges(i) >= 7 || cntDeg2(i);
                    } else {
                        found = cntDeg1(i);
                    }
                    
                } else if (comps[i].size() > 2) {
                    
                    int edges = cntEdges(i);
                    if (edges > 4) {
                        found = cntDeg2(i);
                    } else {
                        found = cntDeg1(i);
                    }
                    
                }
                
            }
            
        }
        
        printf(found ? "YES\n" : "NO\n");
        
    }
    
    return 0;
    
}
