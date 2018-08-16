/*
 Solution to Badge by Ava Pun
 Key concepts: DFS
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1000 + 5;

int N, M;
int adj[MAX];
bool vis[MAX];

int dfs(int u) {
    if (!vis[u]) {
        vis[u] = true;
        return dfs(adj[u]);
    } else {
        return u;
    }
}

int main() {
    
    scanf("%d", &N);
    
    int a;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        adj[i] = a;
    }
    
    for (int i = 1; i <= N; i++) {
        FILL(vis, 0);
        printf("%d\n", dfs(i));
    }
    
    return 0;
}
