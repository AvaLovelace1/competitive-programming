/*
 Solution to TSOC '15 Contest 1 #5 - Giant Ants by Ava Pun
 Key concepts: graph theory, BFS
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, W;
vector<int> adj[101];
bool vis[101];
int dist[101];
int distAnts[101];

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    scanf("%d", &W);
    fill(distAnts, distAnts + N + 1, INT_MAX);
    while (W--) {
        scanf("%d", &a);
        distAnts[a] = 0;
        vis[a] = true;
        q.push(a);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int n : adj[x]) {
            if (!vis[n]) {
                vis[n] = true;
                distAnts[n] = distAnts[x] + 1;
                q.push(n);
            }
        }
    }
    
    fill(dist, dist + N + 1, INT_MAX);
    fill(vis, vis + N + 1, 0);
    vis[1] = true;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int n : adj[x]) {
            if (!vis[n] && distAnts[n] * 4 > dist[x] + 1) {
                vis[n] = true;
                dist[n] = dist[x] + 1;
                q.push(n);
            }
        }
    }
    
    if (dist[N] == INT_MAX) {
        printf("sacrifice bobhob314");
    } else {
        printf("%d", dist[N]);
    }
 
    return 0;
    
}
