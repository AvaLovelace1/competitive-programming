/*
 * Solution to Omkar and Last Class of Math by Ava Pun
 * Key concepts: greedy algorithms, math, number theory
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
const int MAX = 2e5 + 5;

int T, N;

void solve() {
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            cout << N/i << ' ' << N - N/i << '\n';
            return;
        }
    }
    cout << 1 << ' ' << N - 1 << '\n';
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(i, 1, T) {
        cin >> N;
        solve();
    }

}
