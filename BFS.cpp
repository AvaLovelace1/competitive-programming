/*
 ~ Breadth-First Search ~
 
 Traverses a graph, also finds single source shortest paths on an unweighted graph.
 You can also find shortest paths on a graph where weights can be 0 or 1 by using a deque.
 
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
int dist[MAX];
bool vis[MAX];
int S, T;

int bfs(int start, int end) {
    
    fill(vis, vis + N + 1, false);
    fill(dist, dist + N + 1, INF);
    
    queue<int> q;
    q.push(start);
    vis[start] = true;
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist[end];
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    scanf("%d%d", &S, &T);
    int dist = bfs(S, T);
    if (dist == INF) {
        printf("No path from %d to %d\n", S, T);
    } else {
        printf("Shortest path from %d to %d is %d\n", S, T, dist);
    }
    
    return 0;
    
}
