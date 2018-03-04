/*
 ~ Dinic's Algorithm ~
 
 Finds max flow in a network using blocking flow and level graph.
 
 Time complexity: O(V^2E)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 205;
const int MAXE = 205;

int N, M;
piii edges[2 * MAXE + 2 * MAX];
int last[2 * MAX], dist[2 * MAX];
int S, T;
int cnt = 0;

bool bfs() {
    
    fill(dist, dist + N + 1, INF);
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = last[u]; i != -1; i = edges[i].second) {
            int v = edges[i].first.first;
            int w = edges[i].first.second;
            if (dist[v] == INF && w) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist[T] != INF;
    
}

int dfs(int u, int flow) {
    
    if (u == T) {
        return flow;
    }
    
    int ans = 0;
    for (int i = last[u]; i != -1; i = edges[i].second) {
        int v = edges[i].first.first;
        int w = edges[i].first.second;
        if (dist[v] == dist[u] + 1 && w) {
            int res = dfs(v, min(flow, w));
            ans += res;
            edges[i].first.second -= res;
            edges[i ^ 1].first.second += res;
            flow -= res;
            if (!flow) {
                break;
            }
        }
    }
    
    return ans;
}

void addEdge(int a, int b, int d) {
    edges[cnt] = {{b, d}, last[a]};
    last[a] = cnt++;
    edges[cnt] = {{a, 0}, last[b]};
    last[b] = cnt++;
}

int dinic() {
    int maxFlow = 0;
    while (bfs()) {
        maxFlow += dfs(S, INF);
    }
    return maxFlow;
}

int main() {
    
    scanf("%d%d", &N, &M);
    fill(last, last + N + 1, -1);
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        addEdge(a, b, d);
    }
    scanf("%d%d", &S, &T);

    printf("Max flow: %d\n", dinic());
    
    return 0;
    
}
