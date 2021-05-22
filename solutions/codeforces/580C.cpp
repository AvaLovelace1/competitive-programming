/*
 * Solution to Kefa and Park by Ava Pun
 * Key concepts: dynamic programming on trees
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

int N, M;
bool arr[MAX];
vi adj[MAX];
int ans[MAX];
int tot = 0;

void solve(int u, int p, int m) {
    ans[u] = max(ans[p], m + arr[u]);
    if (adj[u].size() == 1 && adj[u][0] == p) tot += ans[u] <= M;

    TRAV(v, adj[u]) {
        if (v != p) solve(v, u, arr[u] ? m + 1 : 0);
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 1, N) cin >> arr[i];
    REP(i, 1, N - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    solve(1, 0, 0);
    cout << tot << '\n';

}
