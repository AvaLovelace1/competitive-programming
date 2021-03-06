/*
 * Solution to COCI '07 Contest 3 #5 Cudak by Ava Pun
 * Key concepts: digit dynamic programming
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

string SA, SB;
int A[20], B[20];
int S;
ll dp[2][2][20][140];
int trace[2][2][20][140];

ll solve(bool mn, bool mx, int d, int tot) {
    if (tot < 0) return 0;

    ll &ans = dp[mn][mx][d][tot];
    if (ans != -1) return ans;
    else if (d == 0) return tot == 0;
    else {
        ans = 0;
        int lo = mn ? A[d] : 0;
        int hi = mx ? B[d] : 9;
        REV(i, hi, lo) {
            ll cnt = solve(
                mn && i == lo,
                mx && i == hi,
                d - 1,
                tot - i
            );
            ans += cnt;
            if (cnt != 0) trace[mn][mx][d][tot] = i;
        }
        return ans;
    }
}

ll findSol() {
    ll ret = 0;
    bool mn = 1, mx = 1;
    int d = 15;
    int tot = S;
    while (d != 0) {
        int lo = mn ? A[d] : 0;
        int hi = mx ? B[d] : 9;
        int i = trace[mn][mx][d][tot];
        ret *= 10;
        ret += i;

        mn = mn && i == lo;
        mx = mx && i == hi;
        d = d - 1;
        tot = tot - i;
    }
    return ret;
}

void conv(string &S, int arr[]) {
    REP(i, 0, (int) S.length() - 1) {
        arr[S.length() - i] = S[i] - '0';
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> SA >> SB >> S;
    conv(SA, A);
    conv(SB, B);

    FILL(dp, -1);
    cout << solve(1, 1, 15, S) << '\n';
    cout << findSol() << '\n';
}

