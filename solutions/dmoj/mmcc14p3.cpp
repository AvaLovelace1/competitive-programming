/*
 Solution to Esdeath by Ava Pun
 Key concepts: graph theory, greedy algorithms, binary search
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, S;
vector<int> adj[5001];
bool vis[5001];
bool tmp[5001];
bool chosen[5001];
pii dist[5001];
int parent[5001];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dist[v].first = dist[u].first + 1;
            parent[v] = u;
            dfs(v);
        }
    }
}

void flood(int u, int d) {
    if (d > 0) {
        for (int v : adj[u]) {
            if (!tmp[v]) {
                vis[v] = true;
                tmp[v] = true;
                flood(v, d - 1);
            }
        }
    }
}

bool possible(int d) {
    fill(vis, vis + N + 1, 0);
    fill(chosen, chosen + N + 1, 0);
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int u = dist[i].second;
        if (!vis[u]) {
            if (count >= S) {
                return false;
            }
            for (int i = 1; i <= d; i++) {
                u = parent[u];
            }
            fill(tmp, tmp + N + 1, 0);
            count++;
            tmp[u] = true;
            vis[u] = true;
            flood(u, d);
        }
    }
    return true;
}

int main() {
    
    scanf("%d%d", &N, &S);
    int a, b;
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        dist[i] = {INT_MAX, i};
    }
    dist[1].first = 0;
    vis[1] = true;
    parent[1] = 1;
    dfs(1);
    
    sort(dist + 1, dist + N + 1, greater<pii>());
    
    int start = 0, end = N / 2, mid = 0;
    while (start < end) {
        mid = (start + end) / 2;
        if (possible(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    
    printf("%d", start);
    
    return 0;
    
}
