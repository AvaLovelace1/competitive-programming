/*
 * Solution to White Sheet by Ava Pun
 * Key concepts: geometry, coordinate compression
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define SZ(x) int(x.size())

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
vi xs, ys;

bool check(double x, double y, int r) {
    int x1 = arr[r][0], y1 = arr[r][1], x2 = arr[r][2], y2 = arr[r][3];
    bool ans = x >= x1 && x <= x2 && y >= y1 && y <= y2;
    return ans;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> arr[i][j];
        }
        xs.pb(arr[i][0]);
        xs.pb(arr[i][2]);
        ys.pb(arr[i][1]);
        ys.pb(arr[i][3]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    for (int i = 0; i < SZ(xs) - 1; ++i) {
        for (int j = 0; j < SZ(ys) - 1; ++j) {
            double x = (double) (xs[i + 1] + xs[i]) / 2;
            double y = (double) (ys[j + 1] + ys[j]) / 2;
            if (check(x, y, 0) && !check(x, y, 1) && !check(x, y, 2)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

}
