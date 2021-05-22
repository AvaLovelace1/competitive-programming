/*
 * Solution to Pashmak and Garden by Ava Pun
 * Key concepts: implementation
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

int X1, Y1, X2, Y2;
int X3, Y3, X4, Y4;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1 == X2) {
        int len = abs(Y1 - Y2);
        X3 = X4 = X1 + len;
        Y3 = Y1;
        Y4 = Y2;
    } else if (Y1 == Y2) {
        int len = abs(X1 - X2);
        Y3 = Y4 = Y1 + len;
        X3 = X1;
        X4 = X2;
    } else if (abs(X1 - X2) != abs(Y1 - Y2)) {
        cout << "-1\n";
        return 0;
    } else {
        X3 = X1;
        Y3 = Y2;
        X4 = X2;
        Y4 = Y1;
    }

    cout << X3 << ' ' << Y3 << ' ' << X4 << ' ' << Y4 << '\n';

}
