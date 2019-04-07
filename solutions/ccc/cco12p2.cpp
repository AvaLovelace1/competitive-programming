/*
 Solution to CCO '12 P2 - The Hungary Games by Ava Pun
 Key concepts: Dijkstra's
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 2e4 + 5;

int N, M;
vii adj[MAX];
int dist[2][MAX];

int main() {

    scanf("%d%d", &N, &M);
    int a, b, l;
    while (M--) {
        scanf("%d%d%d", &a, &b, &l);
        adj[a].pb({b, l});
    }

    FILL(dist, INF);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int d = pq.top().f, u = pq.top().s;
        pq.pop();
        if (dist[1][u] == INF && dist[0][u] != d) {
            if (dist[0][u] == INF) {
                dist[0][u] = d;
            } else {
                dist[1][u] = d;
            }
            for (pii e : adj[u]) {
                int v = e.f, w = e.s;
                if (dist[1][v] == INF) {
                    pq.push({d + w, v});
                } 
            }
        }
    }
    printf("%d\n", dist[1][N] == INF ? -1 : dist[1][N]);

    return 0;
}
