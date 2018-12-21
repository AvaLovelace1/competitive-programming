/*
 Solution to CCC '16 S3 - Phonomenal Reviews by Ava Pun
 Key concepts: DFS, diameter of a tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 100005;

int N, M;
int arr[MAX];
vector<int> adj[MAX];
bool pho[MAX], vis[MAX], onPath[MAX];
int dist[MAX];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v] && onPath[v]) {
            vis[v] = true;
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

bool findPath(int u, int prev) {
    if (pho[u]) {
        onPath[u] = true;
    }
    for (int v : adj[u]) {
        if (v != prev) {
            onPath[u] |= findPath(v, u);
        }
    }
    return onPath[u];
}

int main() {
    
    scanf("%d%d", &N, &M);
    int n;
    for (int i = 0; i < M; i++) {
        scanf("%d", &n);
        pho[n] = true;
    }
    
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (pho[i]) {
            findPath(i, -1);
            break;
        }
    }
    
    int cnt = N;
    
    fill(vis, vis + N, 0);
    n = 0;
    for (int i = 0; i < N; i++) {
        if (onPath[i]) {
            n = i;
            break;
        }
    }
    dist[n] = 0;
    vis[n] = true;
    dfs(n);

    for (int i = n; i < N; i++) {
        if (onPath[i] && dist[i] > dist[n]) {
            n = i;
        }
    }
    
    fill(vis, vis + N, 0);
    dist[n] = 0;
    vis[n] = true;
    dfs(n);
    
    int diam = 0;
    for (int i = 0; i < N; i++) {
        if (onPath[i]) {
            diam = max(diam, dist[i]);
        } else {
            cnt--;
        }
    }

    printf("%d", 2 * (cnt - 1) - diam);
    
    return 0;
}
