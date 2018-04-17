/*
 Solution to VM7WC '16 #5 Gold - Jayden Studies Trees by Ava Pun
 Key concepts: graph theory, diameter of a tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 10005;

int N;
vector<int> adj[MAX];
int dist[MAX];
bool vis[MAX];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dist[1] = 0;
    vis[1] = true;
    dfs(1);

    int n = 1;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > dist[n]) {
            n = i;
        }
    }
    fill(vis, vis + N + 1, 0);
    dist[n] = 0;
    vis[n] = true;
    dfs(n);
    
    int maxN = 0;
    for (int i = 1; i <= N; i++) {
        maxN = max(maxN, dist[i]);
    }
    
    printf("%d", maxN);
    
    return 0;
}
