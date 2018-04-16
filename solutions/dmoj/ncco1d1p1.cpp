/*
 Solution to Mock CCO '18 Contest 1 Problem 1 - A Geometry Problem by Ava Pun
 Key concepts: graph theory, max flow, Dinic's
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2 * 250 + 5;
const int MAXE = 2 * (250 * 251 / 2 + 250 * 3) + 5;

int L, W, N;
pii arr[255];
piii edges[2 * MAXE];
int last[2 * MAX], dist[2 * MAX];
int S, T;
int cnt = 0;

bool bfs() {
    FILL(dist, INF);
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = last[u]; i != -1; i = edges[i].s) {
            int v = edges[i].f.f;
            int w = edges[i].f.s;
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
    for (int i = last[u]; i != -1; i = edges[i].s) {
        int v = edges[i].f.f;
        int w = edges[i].f.s;
        if (dist[v] == dist[u] + 1 && w) {
            int res = dfs(v, min(flow, w));
            ans += res;
            edges[i].f.s -= res;
            edges[i ^ 1].f.s += res;
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

ll distSq(pii a, pii b) {
    return pow(b.f - a.f, 2) + pow(b.s - a.s, 2);
}

int main() {
    
    scanf("%d%d%d", &L, &W, &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    FILL(last, -1);
    S = 2 * N + 1, T = 2 * N + 2;
    for (int i = 1; i <= N; i++) {
        addEdge(i, i + N, 1);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (distSq(arr[i], arr[j]) <= pow(200, 2)) {
                addEdge(i + N, j, INF);
                addEdge(j + N, i, INF);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i].s <= 100) {
            addEdge(S, i, INF);
        }
        if (W - arr[i].s <= 100) {
            addEdge(i + N, T, INF);
        }
    }
    int ans = 0;
    while (bfs()) {
        ans += dfs(S, INF);
    }
    printf("%d\n", ans);

    return 0;
}
