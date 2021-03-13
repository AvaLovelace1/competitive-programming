/*
 * Solution to Bots by Ava Pun
 * Key concepts: combinatorics
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

int N;

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b % 2 == 1) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }
}

ll modInv(ll x) {
    return modPow(x, MOD - 2);
}

ll fact(int n) {
    ll ret = 1;
    REP(i, 1, n) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

ll binom(int n, int k) {
    ll ans = fact(n);
    ans = (ans * modInv(fact(k))) % MOD;
    ans = (ans * modInv(fact(n - k))) % MOD;
    return ans;
}

ll solve(int n) {
    ll ret = (binom(2 * (n + 1), (n + 1)) - 1) % MOD;
    ret = (ret + MOD) % MOD;
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    cout << solve(N) << '\n';

}

