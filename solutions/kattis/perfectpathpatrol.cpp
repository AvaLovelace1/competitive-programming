/*
 * Solution to Perfect Path Patrol by Ava Pun
 * Key concepts: dynamic programming on tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 5e5 + 2;

int N;
vii adj[MAX];
bool vis[MAX];

ll mxPairs(ll totEnds, ll mx) {
    if (totEnds - mx <= mx) {
        return totEnds - mx;
    } else {
        return totEnds / 2;
    }
}

ll solve(int u, int kp) {
    vis[u] = 1;
    ll totEnds = kp, mx = kp;
    ll rest = 0;
    for (auto p : adj[u]) {
        int v = p.f;
        int k = p.s;
        if (!vis[v]) {
            totEnds += k;
            mx = max(mx, (ll) k);
            rest += solve(v, k);
        }
    }
    ll mxp = mxPairs(totEnds, mx);
    ll ret = rest + kp - mxp;
    //cout << u << ' ' << ret << ' ' << rest << ' ' << mxp << ' ' << mx << ' ' <<  totEnds << '\n';
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N - 1; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        ++u, ++v;
        adj[u].pb({v, p});
        adj[v].pb({u, p});
    }

    cout << solve(1, 0) << '\n';

}
