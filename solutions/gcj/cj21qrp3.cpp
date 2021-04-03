/*
 * Solution to Google Code Jam QR '21 P3 - Reversort Engineering by Ava Pun
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
const int MAX = 105;

int T, N, C;
int arr[MAX];
int posns[MAX];

int minCost(int N) {
    return N - 1;
}

int maxCost(int N) {
    return N * (N + 1) / 2 - 1;
}

void solve(int N, int C) {
    REP(i, 1, N) posns[i] = i;

    C -= (N - 1);
    REP(i, 1, N - 1) {
        int len = min(C, N - i);
        int j = i + len;
        reverse(posns + i, posns + j + 1);
        C -= len;
    }

    REP(i, 1, N) {
        arr[posns[i]] = i;
    }
}

void go() {
    if (C < minCost(N) || C > maxCost(N)) {
        cout << "IMPOSSIBLE";
        return;
    }

    solve(N, C);

    REP(i, 1, N) {
        cout << arr[i];
        if (i != N) cout << ' ';
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(i, 1, T) {
        cin >> N >> C;
        cout << "Case #" << i << ": ";
        go();
        cout << '\n';
    }

}

