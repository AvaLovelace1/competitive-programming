/*
 Solution to CCC '13 S4 - Who is Taller? by Ava Pun
 Key concepts: DFS
 */
 
 #include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[1000001];
bool vis[1000001];

void dfs(int n) {
    for (int i : adj[n]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    scanf("%d%d", &a, &b);
    int state = 0;
    fill(vis, vis + N + 1, 0);
    vis[a] = true;
    dfs(a);
    if (vis[b]) {
        state = 1;
    }
    fill(vis, vis + N + 1, 0);
    vis[b] = true;
    dfs(b);
    if (vis[a]) {
        state = -1;
    }
    
    printf(state == 0 ? "unknown" : state == 1 ? "yes" : "no");
    
    return 0;
    
}
