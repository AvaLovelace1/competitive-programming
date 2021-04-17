/*
 * Solution to Dima and Lisa by Ava Pun
 * Key concepts: math, number theory, brute force
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
vi ans;

bool prime(int n) {
    if (n == 1 || n == 0) return 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve(int n) {
    REV(i, n, 1) {
        if (prime(i)) {
            n -= i, ans.pb(i);
            break;
        }
    }
    if (n == 0) return;
    if (prime(n)) {
        ans.pb(n);
        return;
    }
    REV(i, n, 1) {
        if (prime(i) && prime(n - i)) {
            ans.pb(i), ans.pb(n - i);
            return;
        }
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    solve(N);
    cout << SZ(ans) << '\n';
    REP(i, 0, SZ(ans) - 1)
        cout << ans[i] << " \n"[i == SZ(ans) - 1];

}

