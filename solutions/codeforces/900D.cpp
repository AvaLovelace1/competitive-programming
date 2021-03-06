/*
 * Solution to Unusual Sequences by Ava Pun
 * Key concepts: combinatorics, number theory, dynamic programming, math
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

int X, Y;
map<int, ll> dp;

ll fastPow(ll a, int b) {
    if (b == 0) return 1;
    else {
        ll ans = fastPow(a, b / 2);
        ans = (ans * ans) % MOD;
        if (b % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        return ans;
    }
}

ll solve(int y) {
    if (dp.find(y) != dp.end()) return dp[y];
    else if (y == 1) return 1;
    else {
        ll ans = fastPow(2, y - 1);
        for (int d = 1; d * d <= y; ++d) {
            if (y % d == 0) {
                ans = ((ans - solve(d)) % MOD + MOD) % MOD;
                if (d != 1 && y / d != d) {
                    ans = ((ans - solve(y / d)) % MOD + MOD) % MOD;
                }
            }
        }
        return dp[y] = ans;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> X >> Y;
    if (Y % X != 0) {
        cout << 0 << '\n';
    } else {
        cout << solve(Y / X) << '\n';
    }

}

