/*
 * Solution to Number Game by Ava Pun
 * Key concepts: dynamic programming, number theory, math
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
unordered_map<int, bool> dp;

bool solve(int n) {
    if (dp.find(n) != dp.end()) return dp[n];
    if (n == 1) return dp[n] = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i % 2 == 1 && i > 1 && !solve(n / i)) return dp[n] = 1;
            if ((n / i) % 2 == 1 && !solve(i)) return dp[n] = 1;
        }
    }
    if (!solve(n - 1)) return dp[n] = 1;
    return dp[n] = 0;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(i, 1, T) {
        cin >> N;
        cout << (solve(N) ? "Ashishgup\n" : "FastestFinger\n");
    }

}
