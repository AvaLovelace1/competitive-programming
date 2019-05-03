/*
 Solution to DMOPC '18 Contest 6 P3 - Wish Upon a Star by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, M;
vi adj[MAX];
bool vis[MAX];
int compCnt = 0;

void dfs(int u) {
    if (!vis[u]) {
        vis[u] = 1;
        for (int v : adj[u]) {
            dfs(v);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            compCnt++;
            dfs(i);
        }
    }
    printf(M - (N - compCnt) <= 1 ? "YES\n" : "NO\n");
    
    return 0;
}
