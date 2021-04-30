/*
 * Solution to DMOPC '20 Contest 5 P2 - On The Clock by Ava Pun
 * Key concepts: mathematics
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

ll floorDiv(ll a, ll b) {
    return a / b;
}

ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    REP(i, 1, N) {
        ll lo = floorDiv((ll) M * (i - 1), N) + 1;
        ll hi = ceilDiv((ll) M * i, N);
        REP(j, lo, hi) {
            cout << j << ' ' << i << '\n';
        }
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> M >> N;

    cout << M + N - __gcd(M, N) << '\n';
    solve();

}
