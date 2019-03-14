/*
 Solution to USACO '19 February P2 - Moorio Kart by Ava Pun
 Key concepts: graph theory, dynamic programming, combinatorics
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
const int MAX = 1505;

int N, M, X, Y;
vii adj[MAX];
int dist[MAX];
bool vis[MAX];
int compCnt = 0;
int comp[MAX], nComp[MAX];
map<int, int> len[MAX];
ll dp[2][2505];

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ans = ans * a % MOD;
        }
        return ans;
    }
}

void dfs(int u) {
    nComp[compCnt]++;
    comp[u] = compCnt;
    for (pii e : adj[u]) {
        if (!vis[e.f]) {
            vis[e.f] = 1;
            dfs(e.f);
        }
    }
}

void dfs2(int u) {
    for (pii e : adj[u]) {
        if (!vis[e.f]) {
            vis[e.f] = 1;
            dist[e.f] = dist[u] + e.s;
            dfs2(e.f);
        }
    }
}

int main() {

    scanf("%d%d%d%d", &N, &M, &X, &Y);
    int a, b, d;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].pb({b, d});
        adj[b].pb({a, d});
    }
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            compCnt++;
            dfs(i);
        }
    }
    Y -= compCnt * X + 1;
    
    for (int i = 1; i <= N; i++) {
        FILL(vis, 0);
        FILL(dist, 0);
        vis[i] = 1;
        dfs2(i);
        for (int j = i + 1; j <= N; j++) {
            if (comp[i] == comp[j]) {
                len[comp[i]][dist[j]]++;
            }
        }
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= compCnt; i++) {
        int i0 = i & 1;
        for (int j = 0; j <= Y; j++) {
            dp[i0][j] = 0;
            for (auto p : len[i]) {
                if (p.f <= j) {
                    dp[i0][j] += dp[!i0][j - p.f] * p.s % MOD;
                    dp[i0][j] %= MOD;
                } else {
                    break;
                }
            }
        }
    }
    
    ll tot[2] = {}, nWays[2] = {};
    // Bigger than Y
    for (int i = 0; i <= Y; i++) {
        tot[0] += i * dp[compCnt & 1][i] % MOD;
        tot[0] %= MOD;
        nWays[0] += dp[compCnt & 1][i];
        nWays[0] %= MOD;
    }
    
    // Total tracks
    nWays[1] = 1;
    for (int i = 1; i <= compCnt; i++) {
        nWays[1] *= nComp[i] * (nComp[i] - 1) / 2 % MOD;
        nWays[1] %= MOD;
    }
    for (int i = 1; i <= compCnt; i++) {
        ll tmp = nWays[1] * modPow(nComp[i] * (nComp[i] - 1) / 2 % MOD, MOD - 2) % MOD;
        for (auto p : len[i]) {
            tot[1] += tmp * p.f % MOD * p.s % MOD;
            tot[1] %= MOD;
        }
    }
    
    for (int i = 0; i < 2; i++) {
        // Choose permutation of farms
        for (int j = 1; j <= compCnt - 1; j++) {
            tot[i] = tot[i] * j % MOD;
            nWays[i] = nWays[i] * j % MOD;
        }
        // Choose direction of track in each farm, then count entire track only one way
        tot[i] = tot[i] * modPow(2, compCnt - 1) % MOD;
        nWays[i] = nWays[i] * modPow(2, compCnt - 1) % MOD;
        // Add additional roads
        tot[i] = (tot[i] + nWays[i] * compCnt % MOD * X % MOD) % MOD;
    }
    
    ll ans = (tot[1] - tot[0] + MOD) % MOD;
    printf("%lld\n", ans);
    
    return 0;
}
