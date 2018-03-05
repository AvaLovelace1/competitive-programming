/*
 Solution to Shortest Path by Ava Pun
 Key concepts: graph theory, BFS
 */

#include <bits/stdc++.h>

using namespace std;

int N;
bool adj[105][105];
int dist[105];
bool vis[105];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    dist[0] = 0;
    vis[0] = true;
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (adj[x][i] && !vis[i]) {
                vis[i] = true;
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
    
    printf("%d", dist[N - 1]);
    
    return 0;
    
}
