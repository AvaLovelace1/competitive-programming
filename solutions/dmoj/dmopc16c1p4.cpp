/*
 Solution to DMOPC '16 Contest 1 P4 - Tree Appraisal by Ava Pun
 Key concepts: dynamic programming on trees
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
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2e5 + 5;

int N;
int arr[MAX];
vi adj[MAX];
ll dp[MAX], dpE[MAX], dpL[MAX], dpW[MAX], sz[MAX];

ll solve(int u, int p) {
    dpW[u] = arr[u];
    sz[u] = 1;
    ll dpE0 = 0, dpL0 = 0, dpW0 = 0, sz0 = 0;
    for (int v : adj[u]) {
        if (v != p) {
            solve(v, u);
            dp[u] += dpE0 * sz[v] + dpE[v] * sz0 + dpL0 * dpW[v] + dpW0 * dpL[v];
            dp[u] += arr[u] * (dpL0 * sz[v] + dpL[v] * sz0);
            dp[u] += 2 * (dpW0 * sz[v] + dpW[v] * sz0 + arr[u] * sz0 * sz[v]);
            dpE[u] += dpE[v] + dpL[v] * arr[u] + dpW[v] + arr[u] * sz[v];
            dpL[u] += dpL[v] + sz[v];
            dpW[u] += dpW[v] + arr[u] * sz[v];
            sz[u] += sz[v];
            dpE0 += dpE[v], dpL0 += dpL[v], dpW0 += dpW[v], sz0 += sz[v];
        }
    }
    return dp[u];
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    int a, b;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    solve(1, -1);
    printf("%lld\n", accumulate(dp + 1, dp + N + 1, 0LL) + accumulate(dpE + 1, dpE + N + 1, 0LL));
    
    return 0;
}
