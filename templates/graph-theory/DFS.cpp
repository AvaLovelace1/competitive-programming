/*
 ~ Depth-First Search ~
 
 Traverses a graph.
 The basis of other cool algorithms like Tarjan's.
 Can be implemented with or without recursion.
 
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

int N, M;
vector<int> adj[MAX];
bool vis[MAX];

void dfs(int u) {
    printf("%d ", u);
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}

void dfsIter(int start) {

    stack<int> st;
    st.push(start);
    vis[start] = true;
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        printf("%d ", u);
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                st.push(v);
            }
        }
    }
    
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    printf("Recursive DFS:\n");
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
            printf("\n");
        }
    }
    
    printf("\n");    
    fill(vis, vis + N + 1, false);
    
    printf("Iterative DFS:\n");
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfsIter(i);
            printf("\n");
        }
    }
    
    return 0;
    
}
