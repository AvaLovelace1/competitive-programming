/*
 Solution to Mock CCO '18 Contest 3 Problem 3 - Roger Plays Some Chess by Ava Pun
 Key concepts: graph theory, BFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 35;

const pii moves[] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
int R, C;
int arr[MAX][MAX];
vii adj[2][MAX][MAX], meta[2][MAX][MAX];
pii S, T;
ll dist[2][MAX][MAX], dp[2][MAX][MAX];

void addEdge(int i, int j, int k, int i1, int j1, int k1, int w, vii adj[][MAX][MAX]) {
    adj[i][j][k].pb({{i1, j1}, {k1, w}});
}

void bfs(int i0, int j0, int k0, vii adj[][MAX][MAX]) {
    
    queue<piii> q[2];
    q[0].push({i0, {j0, k0}});
    FILL(dist, -1);
    FILL(dp, 0);
    dist[i0][j0][k0] = 0;
    dp[i0][j0][k0] = 1;
    
    while (!q[0].empty() || !q[1].empty()) {
        bool idx = q[0].empty();
        piii x = q[idx].front();
        q[idx].pop();
        int i = x.f, j = x.s.f, k = x.s.s;
        for (piiii p : adj[i][j][k]) {
            int i1 = p.f.f, j1 = p.f.s, k1 = p.s.f, w = p.s.s;
            if (dist[i1][j1][k1] == -1) {
                dist[i1][j1][k1] = dist[i][j][k] + w;
                dp[i1][j1][k1] = dp[i][j][k];
                q[w].push({i1, {j1, k1}});
            } else if (dist[i1][j1][k1] == dist[i][j][k] + w) {
                dp[i1][j1][k1] += dp[i][j][k];
            }
        }
    }
    
}

int main() {
    
    scanf("%d%d", &R, &C);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 3) {
                S = {i, j};
            } else if (arr[i][j] == 4) {
                T = {i, j};
            }
        }
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] != 2) {
                addEdge(0, i, j, 1, i, j, arr[i][j] == 0 ? 1 : 0, adj);
                for (pii p : moves) {
                    int i1 = i + p.f, j1 = j + p.s;
                    if (i1 > 0 && i1 <= R && j1 > 0 && j1 <= C && arr[i1][j1] != 2) {
                        addEdge(1, i, j, 0, i1, j1, 0, adj);
                    }
                }
            }
        }
    }
    
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] != 2 && arr[i][j] != 1) {
                bfs(0, i, j, adj);
                for (int i1 = 1; i1 <= R; i1++) {
                    for (int j1 = 1; j1 <= C; j1++) {
                        if ((i != i1 || j != j1) && dist[1][i1][j1] == ((arr[i][j] == 0) + (arr[i1][j1] == 0))) {
                            addEdge(0, i, j, 0, i1, j1, 1, meta);
                        }
                    }
                }
            }
        }
    }
    
    bfs(0, S.f, S.s, meta);

    if (dist[0][T.f][T.s] != -1) {
        printf("%lld\n", dist[0][T.f][T.s] - 1);
        printf("%lld\n", dp[0][T.f][T.s]);
    } else {
        printf("%d\n", -1);
    }
    
    return 0;
}
