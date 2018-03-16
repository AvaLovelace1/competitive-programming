/*
 Solution to Mock CCC '18 Contest 5 S5 - Carol's Cute Construction by Ava Pun
 Key concepts: graph theory, max flow, Dinic's
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 205;

int N;
string arr[MAX];
int last[2 * MAX * MAX], dist[2 * MAX * MAX];
piii edges[6 * MAX * MAX];
int S, T;
int cnt = 0;

char next(char c) {
    switch (c) {
        case 'C':
            return 'A';
            break;
        case 'A':
            return 'L';
            break;
        case 'L':
            return 'I';
            break;
    }
    return 0;
}

bool valid(int x0, int y0, int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && next(arr[x0][y0]) == arr[x][y];
}

bool bfs() {
    
    memset(dist, INF, sizeof(dist));
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
        if (dist[v] == dist[u] + 1) {
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
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    memset(last, -1, sizeof(last));
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    S = 2 * N * N, T = 2 * N * N + 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'C') {
                addEdge(S, i * N + j, INF);
            }
            if (arr[i][j] != 'I') {
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (valid(i, j, i + k, j + l)) {
                            addEdge(i * N + j + (N * N), (i + k) * N + (j + l), INF);
                        }
                    }
                }
            } else {
                addEdge(i * N + j + (N * N), T, INF);
            }
            addEdge(i * N + j, i * N + j + (N * N), 1);
        }
    }
    
    int ans = 0;
    while (bfs()) {
        ans += dfs(S, INF);
    }
    cout << ans << "\n";
    
    return 0;
    
}
