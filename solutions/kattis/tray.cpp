/*
 * Solution to Tray Bien by Ava Pun
 * Key concepts: dynamic programming
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

int C, N;
int R = 3;
bool blocked[4][25];
ll dp[2][2][2][25];

inline bool valid(int r, int c) {
    return r >= 1 && r <= R && c >= 1 && c <= C && !blocked[r][c];
}

ll solve(vector<bool> bs, int c);

ll gen(vector<bool> bs, vector<bool> newBs, int r, int c) {
    if (r > R) return solve(newBs, c + 1);
    else {
        ll ans = 0;
        if (bs[r - 1] == 1) {
            ans += gen(bs, newBs, r + 1, c); // 2x1 horizontal
        } else {
            if (!valid(r, c)) {
                ans += gen(bs, newBs, r + 1, c); // no tray
            } else {
                ans += gen(bs, newBs, r + 1, c); // 1x1
                if (valid(r + 1, c) && !bs[r + 1 - 1]) {
                    ans += gen(bs, newBs, r + 2, c); // 2x1 vertical
                }
                if (valid(r, c + 1)) {
                    newBs[r - 1] = 1;
                    ans += gen(bs, newBs, r + 1, c); // 2x1 horizontal
                }
            }
        }
        return ans;
    }
}

ll solve(vector<bool> bs, int c) {
    ll &ans = dp[bs[0]][bs[1]][bs[2]][c];
    if (ans != -1) return ans;
    else if (c > C) return ans = 1;
    else {
        vector<bool> newBs = {0, 0, 0};
        ll tot = gen(bs, newBs, 1, c);
        return ans = tot;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> C >> N;
    REP(i, 1, N) {
        double x, y;
        cin >> x >> y;
        int r = (int) y + 1;
        int c = (int) x + 1;
        blocked[r][c] = 1;
    }

    FILL(dp, -1);
    vector<bool> bs = {0, 0, 0};
    cout << solve(bs, 1) << '\n';

}

