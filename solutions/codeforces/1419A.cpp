/*
 * Solution to Digit Game by Ava Pun
 * Key concepts: implementation, greedy algorithms
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

int T, N;
string S;

int solve() {
    if (N % 2 == 0) {
        for (int i = 2; i <= N; i += 2) {
            if ((S[i - 1] - '0') % 2 == 0) return 2;
        }
        return 1;
    } else {
        for (int i = 1; i <= N; i += 2) {
            if ((S[i - 1] - '0') % 2 == 1) return 1;
        }
        return 2;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(t, 1, T) {
        cin >> N >> S;
        cout << solve() << '\n';
    }

}
