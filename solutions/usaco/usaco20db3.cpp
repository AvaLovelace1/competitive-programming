/*
 * Solution to USACO '20 December B3 - Stuck in a Rut by Ava Pun
 * Key concepts: implementation, simulation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 52;

int N;
int NN = 0, NE = 0;
piii north[MAX], east[MAX];
int ans[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        if (c == 'N') {
            ++NN;
            cin >> north[NN].f.f >> north[NN].f.s; // x, y
            north[NN].s = i;
        } else {
            ++NE;
            cin >> east[NE].f.s >> east[NE].f.f; // y, x
            east[NE].s = i;
        }
    }
    sort(north + 1, north + NN + 1);
    sort(east + 1, east + NE + 1);

    FILL(ans, -1);

    for (int i = 1; i <= NE; ++i) {
        for (int j = 1; j <= NN; ++j) {
            int xE = east[i].f.s;
            int yE = east[i].f.f;
            int cowE = east[i].s;
            int xN = north[j].f.f;
            int yN = north[j].f.s;
            int cowN = north[j].s;
            if (ans[cowN] == -1 && xN > xE && yN < yE) {
                if (xN - xE > yE - yN) {
                    ans[cowE] = xN - xE;
                    break;
                } else if (xN - xE < yE - yN) {
                    ans[cowN] = yE - yN;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (ans[i] == -1) {
            cout << "Infinity\n";
        } else {
            cout << ans[i] << '\n';
        }
    }

}
