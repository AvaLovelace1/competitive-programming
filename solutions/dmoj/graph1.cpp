/*
 Solution to Breaking the Friend Chain by Ava Pun
 Key concepts: graph theory, DFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

int N, M, X, Y;
vi adj[MAX];
bool vis[MAX];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    scanf("%d%d", &X, &Y);
    
    vis[X] = true;
    dfs(X);
    printf("%d\n", vis[Y] ? 1 : 0);

    return 0;
}
