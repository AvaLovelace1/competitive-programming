/*
 * Solution to Convex Shape by Ava Pun
 * Key concepts: prefix sum array, brute force
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
bool arr[55][55];
int psa[55][55];

int quer(int r1, int c1, int r2, int c2) {
    return psa[r2][c2] - psa[r1 - 1][c2] - psa[r2][c1 - 1] + psa[r1 - 1][c1 - 1];
}

bool full(int r1, int c1, int r2, int c2) {
    int sz = (r2 - r1 + 1) * (c2 - c1 + 1);
    return quer(r1, c1, r2, c2) == sz;
}

bool canGo(int r1, int c1, int r2, int c2) {
    bool ans = (full(r1, c1, r1, c2) && full(r1, c2, r2, c2)) ||
        (full(r1, c1, r2, c1) && full(r2, c1, r2, c2));
    return ans;
}

bool solve() {
    REP(r1, 1, N) {
        REP(c1, 1, M) {
            REP(r2, r1, N) {
                REP(c2, 1, M) {
                    if (arr[r1][c1] && arr[r2][c2]
                            && !canGo(r1, c1, r2, c2)) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 1, N) {
        REP(j, 1, M) {
            char c;
            cin >> c;
            arr[i][j] = (c == 'B');
            psa[i][j] = arr[i][j];
        }
    }

    REP(i, 1, N) {
        REP(j, 1, M) {
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }

    cout << (solve() ? "YES" : "NO") << '\n';

}
