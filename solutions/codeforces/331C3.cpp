/*
 * Solution to The Great Julya Calendar by Ava Pun
 * Key concepts: dynamic programming, greedy algorithms
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

ll N;
map<ll, map<int, pair<ll, int>>> dp;

pair<int, ll> getSplit(ll n) {
    ll lead = n;
    ll pow10 = 1;
    while (lead >= 10) lead /= 10, pow10 *= 10;
    return {(int) lead, n % pow10};
}

// returns
// first: number of steps needed to reduce n to 0 or less
// second: amount less than 0 it will end up as
pair<ll, int> solve(ll n, int mx) {
    if (dp.find(n) != dp.end() && dp[n].find(mx) != dp[n].end()) return dp[n][mx];

    auto &ans = dp[n][mx];
    if (n == 0) return ans = {0, 0};
    else if (n < 10) return ans = {1, max(0, mx - (int) n)};
    else {
        auto split = getSplit(n);
        int lead = split.f;
        ll rest = split.s;
        int newMx = max(mx, lead);

        auto subProb1 = solve(rest, newMx);
        ll steps1 = subProb1.f;
        int under1 = subProb1.s;

         if (under1 == 0) {
            auto subProb2 = solve(n - rest - newMx, mx);
            ll steps2 = subProb2.f;
            int under2 = subProb2.s;
            return ans = {steps1 + steps2 + 1, under2};
        } else {
            auto subProb2 = solve(n - rest - under1, mx);
            ll steps2 = subProb2.f;
            int under2 = subProb2.s;
            return ans = {steps1 + steps2, under2};
        }
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    cout << solve(N, 0).f << '\n';

}

