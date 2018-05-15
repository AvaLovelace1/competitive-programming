/*
 Solution to CCC '18 J5 - Choose your own path by Ava Pun
 Key concepts: BFS
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a));

typedef vector<int> vi;
const int INF = 0x3F3F3F3F;
const int MAX = 10005;

int N;
vi adj[MAX];
int dist[MAX];

int main() {

    scanf("%d", &N);
    int n, a;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &a);
            adj[i].pb(a);
        }
    }

    FILL(dist, INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    printf(*max_element(dist + 1, dist + N + 1) == INF ? "N\n" : "Y\n");
    int ans = INF;
    for (int i = 1; i <= N; i++) {
        if (adj[i].empty()) {
            ans = min(ans, dist[i]);
        }
    }
    printf("%d\n", ans + 1);

    return 0;
}
