/*
 Solution to 336 - A Node Too Far by Ava Pun
 Key concepts: BFS
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int M, Q;
unordered_map<int, vi> adj;
unordered_map<int, int> dist;

int main() {

    scanf("%d", &M);
    while (M) {
        adj.clear();
        int a, b;
        for (int i = 1; i <= M; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        scanf("%d%d", &a, &b);
        while (a || b) {
            Q++;
            int ans = 0;
            if (adj.find(a) == adj.end()) {
                ans = adj.size();
            } else {
                for (auto p : adj) {
                    dist[p.f] = -1;
                }
                queue<int> q;
                q.push(a);
                dist[a] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : adj[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }
                for (auto p : adj) {
                    if (dist[p.f] > b || dist[p.f] == -1) {
                        ans++;
                    }
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Q, ans, a, b);
            scanf("%d%d", &a, &b);
        }
        scanf("%d", &M);
    }

    return 0;
}
