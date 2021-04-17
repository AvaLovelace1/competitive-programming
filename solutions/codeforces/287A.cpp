/*
 * Solution to IQ Test by Ava Pun
 * Key concepts: brute force, implementation
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

bool arr[5][5];

bool good() {
    REP(i, 1, 3) {
        REP(j, 1, 3) {
            if (arr[i + 1][j] == arr[i][j] &&
                arr[i][j + 1] == arr[i][j] &&
                arr[i + 1][j + 1] == arr[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

bool solve() {
    if (good()) return 1;
    REP(i, 1, 4) {
        REP(j, 1, 4) {
            arr[i][j] ^= 1;
            if (good()) return 1;
            arr[i][j] ^= 1;
        }
    }
    return 0;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    REP(i, 1, 4) {
        REP(j, 1, 4) {
            char c;
            cin >> c;
            arr[i][j] = c == '#';
        }
    }
    cout << (solve() ? "YES" : "NO") << "\n";

}

