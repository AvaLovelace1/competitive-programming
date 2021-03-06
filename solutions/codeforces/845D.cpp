/*
 * Solution to Driving Test by Ava Pun
 * Key concepts: stack, greedy algorithms
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

int N;
int type[MAX], val[MAX];
const int SPD = 1, OT = 2, SPD_SIGN = 3, OT_SIGN = 4, NSPD_SIGN = 5, NOT_SIGN = 6;

int solveOT() {
    int ret = 0;
    int signs = 0;
    REP(i, 1, N) {
        if (type[i] == NOT_SIGN) ++signs;
        else if (type[i] == OT_SIGN) signs = 0;
        else if (type[i] == OT) ret += signs, signs = 0;
    }
    return ret;
}

int solveSpeed() {
    int ret = 0;
    stack<int> st;
    int curSpeed = 0;
    REP(i, 1, N) {
        if (type[i] == SPD_SIGN) st.push(val[i]);
        else if (type[i] == NSPD_SIGN) {
            while (!st.empty()) st.pop();
        } else if (type[i] == SPD) curSpeed = val[i];
        while (!st.empty() && st.top() < curSpeed) st.pop(), ++ret;
    }
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> type[i];
        if (type[i] == SPD || type[i] == SPD_SIGN) cin >> val[i];
    }

    int ans = solveOT() + solveSpeed();
    cout << ans << '\n';

}

