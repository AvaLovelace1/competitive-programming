/*
 Solution to GENESIS by Ava Pun
 Key concepts: graph theory, min cut, Dinic's
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 105;
const int MAXE = 1005;

int N, M;
piii edges[2 * MAXE + 2 * MAX];
int last[2 * MAX], dist[2 * MAX];
int S, T;
int cnt = 0;

bool bfs() {
    
    fill(dist, dist + 2 * N + 1, INF);
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

int main() {
    
    scanf("%d", &N);
    fill(last, last + 2 * N, -1);
    S = 1, T = N + N;
    int a, b;
    //scanf("%d", &a);
    for (int i = 1; i < N; i++) {
        scanf("%d", &a);
        addEdge(i, i + N, a);
    }
    //addEdge(1, 1 + N, INF);
    addEdge(N, N + N, INF);
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &a, &b);
        addEdge(a + N, b, INF);
    }
    
    int maxFlow = 0;
    while (bfs()) {
        maxFlow += dfs(S, INF);
    }
    printf("%d", maxFlow);
    
    return 0;
    
}
