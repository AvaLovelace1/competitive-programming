/*
 * Solution to Squawk Virus by Ava Pun
 * Key concepts: simulation, graph theory
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
const int MAX = 105;

int N, M, S, T;
vi adj[MAX];
ll ans[12][MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> S >> T;
    ++S;
    REP(i, 1, M) {
        int x, y;
        cin >> x >> y;
        ++x, ++y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ans[0][S] = 1;
    REP(i, 1, T) {
        REP(u, 1, N) {
            TRAV(v, adj[u]) {
                ans[i][v] += ans[i - 1][u];
            }
        }
    }
    ll tot = accumulate(ans[T] + 1, ans[T] + N + 1, 0LL);
    cout << tot << '\n';

}

