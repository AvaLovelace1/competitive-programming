/*
 Solution to WC18 #3 - Gym Tour by Ava Pun
 Key concepts: DFS, graph theory
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
const int MAX = 1e5 + 5;

int N, K, F;
bool gym[MAX];
vii adj[MAX];
int edgeCnt = 0;
int dist[MAX], dep[MAX], weight[MAX];

int dfs(int u, int prev) {
    int cnt = gym[u];
    for (pii &e : adj[u]) {
        int v = e.f;
        if (v != prev) {
            dep[v] = dep[u] + 1;
            int tmp = dfs(v, u);
            if (tmp > 0) {
                edgeCnt++;
                weight[e.s] = 0;
                cnt += tmp;
            }
        }
    }
    return cnt;
}

void dfs2(int u, int prev) {
    for (pii &e : adj[u]) {
        int v = e.f, w = weight[e.s];
        if (v != prev) {
            dist[v] = dist[u] + w;
            dfs2(v, u);
        }
    }
}

int main() {
    
    scanf("%d%d%d", &N, &K, &F);
    int a, b;
    gym[1] = 1;
    for (int i = 1; i <= K; i++) {
        scanf("%d", &a);
        gym[a] = 1;
    }
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb({b, i});
        adj[b].pb({a, i});
        weight[i] = 1;
    }
    
    dfs(1, -1);
    dfs2(1, -1);
    
    int maxD = -1;
    for (int i = 1; i <= N; i++) {
        if (gym[i]) {
            maxD = max(maxD, dep[i]);
        }
    }
    
    printf("%d\n", min(edgeCnt * 2 - maxD, edgeCnt + dist[F]));
    
    return 0;
}
