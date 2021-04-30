/*
 * Solution to DMOPC '20 Contest 5 P5 - Slacking Off Again by Ava Pun
 * Key concepts: ad hoc
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

int N, M;

string makeThueMorse(int len) {
    string ret = "B";
    while ((int) ret.length() < len) {
        int curLen = (int) ret.length();
        REP(i, 0, curLen - 1) {
            ret += (ret[i] == 'B' ? 'Y' : 'B');
        }
    }
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;

    cout << 0 << '\n';
    string thueMorse = makeThueMorse(N + M);
    REP(i, 0, N - 1) {
        REP(j, 0, M - 1) {
            cout << thueMorse[i + j];
        }
        cout << '\n';
    }

}
