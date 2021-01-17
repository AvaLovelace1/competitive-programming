/*
 * Solution to USACO '17 December B1 - Blocked Billboard by Ava Pun
 * Key concepts: geometry, implementation
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
int arr[3][4];

int solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int w = max(0, min(x4, x2) - max(x3, x1)), h = max(0, min(y4, y2) - max(y3, y1));

    int W = x2 - x1, H = y2 - y1;
    return W * H - w * h;
}

int main() {

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << solve(arr[0][0], arr[0][1], arr[0][2], arr[0][3], arr[2][0], arr[2][1], arr[2][2], arr[2][3]) +
        solve(arr[1][0], arr[1][1], arr[1][2], arr[1][3], arr[2][0], arr[2][1], arr[2][2], arr[2][3]) << '\n';

}
