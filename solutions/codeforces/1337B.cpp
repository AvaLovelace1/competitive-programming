/*
 * Solution to Kana and Dragon Quest game by Ava Pun
 * Key concepts: greedy algorithms, implementation
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

int T, X, N, M;

bool solve() {
    cin >> X >> N >> M;
    REP(i, 1, N) {
        int nxt = X / 2 + 10;
        if (nxt >= X) break;
        X = nxt;
    }
    REP(j, 1, M) {
        int nxt = X - 10;
        X = nxt;
    }
    return X <= 0;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(i, 1, T) {
        cout << (solve() ? "YES\n" : "NO\n");
    }

}
