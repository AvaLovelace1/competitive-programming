/*
 Solution to Connected Components by Ava Pun
 Key concepts: graph theory, connected components, DFS
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, bool> pii;
const int MAX = 1005;

int N;
bool adj[MAX][MAX];
bool vis[MAX];

vector<int> dfs(int u) {
    vector<int> l;
    for (int v = 1; v <= N; v++) {
        if (adj[u][v] && !vis[v]) {
            vis[v] = true;
            vector<int> l2 = dfs(v);
            l.insert(l.end(), l2.begin(), l2.end());
        }
    }
    l.push_back(u);
    return l;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            vector<int> l = dfs(i);
            sort(l.begin(), l.end());
            for (int j : l) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    
    return 0;
    
}
