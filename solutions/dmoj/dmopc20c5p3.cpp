/*
 * Solution to DMOPC '20 Contest 5 P3 - Bottom Row by Ava Pun
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
const int MAX = 1e6 + 5;

int N, K;
int r2c[MAX], c2r[MAX];
int mostRight[MAX], mostDown[MAX];

void calc(int r2c[], int mostRight[]) {
    int prev = 1;
    REP(i, 1, N + 1) {
        if (i == N + 1 || r2c[i] == 0 || (i != 1 && r2c[i] != r2c[i - 1] + 1)) {
            REP(j, prev, i - 1) {
                mostRight[j] = max(mostRight[j], r2c[i - 1] + 1);
            }
            prev = i;
            if (r2c[i] > r2c[i - 1]) return;
        }
        if (i == N + 1 || r2c[i] == 0) return;
    }
}

void calcRightFromDown() {
    REP(i, 1, N) {
        int &x = mostRight[mostDown[i] - 1];
        x = max(x, i + 1);
    }
    REV(i, N, 1) {
        mostRight[i] = max(mostRight[i], mostRight[i + 1]);
    }
}

void solve() {
    if (mostRight[1] > N || mostRight[N] > 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int c = N;
    REP(r, 1, N) {
        int nxtC = mostRight[r];
        int stepsRight = c - nxtC;
        REP(i, 1, stepsRight) cout << "R";
        c = nxtC;
        if (r != N) cout << "U";
    }
    cout << '\n';
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> K;
    REP(i, 1, K) {
        int r, c;
        cin >> r >> c;
        c = N - c + 1;
        r2c[r] = c;
        c2r[c] = r;
    }

    REP(i, 1, N) mostRight[i] = mostDown[i] = 1;
    calc(r2c, mostRight);
    calc(c2r, mostDown);
    calcRightFromDown();

    solve();

}
