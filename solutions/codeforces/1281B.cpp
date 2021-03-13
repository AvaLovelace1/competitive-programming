/*
 * Solution to Azamon Web Services by Ava Pun
 * Key concepts: greedy algorithms
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

int T;
string S, C;

int mnIdx(string &S, int start) {
    int ret = start;
    REP(i, start, (int) S.length() - 1) {
        if (S[i] <= S[ret]) ret = i;
    }
    return ret;
}

void solve() {
    cin >> S >> C;
    REP(i, 0, (int) S.length() - 2) {
        int mn = mnIdx(S, i + 1);
        if (S[mn] < S[i]) {
            swap(S[mn], S[i]);
            break;
        }
    }
    if (S < C) cout << S << '\n';
    else cout << "---\n";
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(test, 1, T) {
        solve();
    }

}

