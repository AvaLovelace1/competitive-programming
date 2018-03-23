/*
 Solution to Mock CCC '18 Contest 5 J5/S3 - Carol's Cute Chase by Ava Pun
 Key concepts: graph theory, BFS, brute force
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;

int N, M;
bool adj[55][55];
pii edges[2500];
bool vis[55];

bool bfs(pii e) {
    
    fill(vis, vis + N + 1, false);
    
    queue<int> q;
    q.push(1);
    vis[1] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (!vis[i] && adj[x][i] && !(x == e.first && i == e.second)) {
                vis[i] = true;
                if (i == N) {
                    return true;
                }
                q.push(i);
            }
        }
    }
    
    return vis[N];
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        adj[a][b] = 1;
        edges[i] = {a, b};
    }
    
    for (int i = 0; i < M; i++) {
        printf(bfs(edges[i]) ? "YES\n" : "NO\n");
    }
    
    return 0;
}
