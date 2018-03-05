/*
 Solution to Travelling Salesmen by Ava Pun
 Key concepts: graph theory, BFS
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e4 + 5;

int N, M, K;
vector<int> adj[MAX];
bool vis[MAX];
int dist[MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &a);
        vis[a] = true;
        dist[a] = 0;
        q.push(a);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int n : adj[x]) {
            if (!vis[n]) {
                vis[n] = true;
                dist[n] = dist[x] + 1;
                q.push(n);
            }
        }
    }
    
    int maxN = INT_MIN;
    for (int i = 1; i <= N; i++) {
        maxN = max(maxN, dist[i]);
    }
    printf("%d", maxN);
    
    return 0;
    
}
