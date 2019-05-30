/*
 Solution to A Fundraising Problem by Ava Pun
 Key concepts: successor graph, dynamic programming
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

int N;
int arr[MAX], nxt[MAX];
bool inCycle[MAX], vis[MAX], vis1[MAX];
ll dp[MAX][2][2];
vi adj[MAX];

int dfs(int u) {
    if (vis[u]) {
        return u;
    }
    vis[u] = 1;
    int lo = dfs(nxt[u]);
    if (lo != -1) {
        inCycle[u] = 1;
    }
    return lo == u ? -1 : lo;
}

void dfs1(int u) {
    if (!vis1[u]) {
        vis1[u] = 1;
        for (int v : adj[u]) {
            dfs1(v);
        }
        dfs1(nxt[u]);
    }
}

ll solve(int u, int b, int t, int p) {
    ll &ans = dp[u][t][p];
    if (ans == -1) {
        ans = arr[u] * p;
        bool last = 0;
        for (int v : adj[u]) {
            if (v == b) {
                last = 1;
            }
        }
        if (last && t && p) {
            return ans = -INFL;
        }
        for (int v : adj[u]) {
            if (v != b) {
                if (!p) {
                    ans += max(solve(v, b, t, 1), solve(v, b, t, 0));
                } else {
                    ans += solve(v, b, t, 0);
                }
            }
        }
    }
    return ans;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i], &nxt[i]);
        adj[nxt[i]].pb(i);
    }
    for (int i = 1; i <= N; i++) {
        if (!vis1[i]) {
            dfs(i);
            dfs1(i);
        }
    }
    FILL(dp, -1);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (inCycle[i] && dp[i][0][0] == -1) {
            ans += max(solve(i, i, 0, 0), solve(i, i, 1, 1));
        }
    }
    printf("%lld\n", ans);

    return 0;
}
