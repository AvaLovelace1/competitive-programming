/*
 * Solution to CEOI '19 P5 - Magic Tree by Ava Pun
 * Key concepts: dynamic programming on trees, difference array, heuristic merge
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 5;

int N, M, K;
vi adj[MAX];
struct fruit {
    int d, w;
} arr[MAX];

// sum_i=1^d dp[u][i] = answer for subtree u after d days
map<int, ll> dp[MAX];

void solve(int u) {
    TRAV(v, adj[u]) {
        solve(v);
        if (dp[u].size() < dp[v].size()) swap(dp[u], dp[v]);
        TRAV(p, dp[v]) dp[u][p.f] += p.s;
    }
    if (arr[u].w > 0) dp[u][arr[u].d] += arr[u].w;

    ll cur = arr[u].w;
    vi zeros{};
    for (auto it = dp[u].upper_bound(arr[u].d); it != dp[u].end(); ++it) {
        it->s -= cur;
        if (it->s < 0) {
            cur = -it->s;
            it->s = 0;
            zeros.pb(it->f);
        } else break;
    }
    for (int v : zeros) dp[u].erase(v);
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> K;
    REP(i, 2, N) {
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    REP(i, 1, M) {
        int v, d, w;
        cin >> v >> d >> w;
        arr[v] = fruit{d, w};
    }

    solve(1);

    ll ans = 0;
    TRAV(p, dp[1]) ans += p.s;
    cout << ans << '\n';
}
