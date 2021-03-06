/*
 * Solution to Digits Sequence (Hard Edition) by Ava Pun
 * Key concepts: implementation
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

ll K;

int nthDigit(ll n, ll idx) {
    string strN = to_string(n);
    return strN[idx - 1] - '0';
}

int solve(ll k) {
    ll pow = 1;
    for (int i = 1; ; ++i) {
        ll nDigits = 9 * pow * i;
        if (k - nDigits <= 0) {
            ll num = pow + (k + i - 1)/i - 1;
            ll digitIdx = k % i == 0 ? i : k % i;
            return nthDigit(num, digitIdx); 
        }
        k -= nDigits;
        pow *= 10;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> K;
    cout << solve(K) << '\n';

}

