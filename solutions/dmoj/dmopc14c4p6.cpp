/*
 Solution to DMOPC '14 Contest 5 P6 - Save Nagato! by Ava Pun
 Key concepts: diameter of a tree
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
const int MAX = 5e5 + 5;

int N;
vi adj[MAX];
int dist[2][MAX];

void dfs(int u, int prev, int dist[]) {
    for (int v : adj[u]) {
        if (v != prev) {
            dist[v] = dist[u] + 1;
            dfs(v, u, dist);
        }
    }
}

int furthest(int dist[]) {
    return (int) (max_element(dist + 1, dist + N + 1) - dist);
}

int main() {
    
    scanf("%d", &N);
    int a, b;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b), adj[b].pb(a);
    }
    
    dfs(1, -1, dist[0]);
    dfs(furthest(dist[0]), -1, dist[1]);
    FILL(dist[0], 0);
    dfs(furthest(dist[1]), -1, dist[0]);
    
    for (int i = 1; i <= N; i++) {
        printf("%d\n", max(dist[0][i], dist[1][i]) + 1);
    }
    
    return 0;
}
