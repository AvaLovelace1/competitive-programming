/*
 * Solution to USACO '19 February S2 - Painting the Barn by Ava Pun
 * Key concepts: 2D difference array
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N, K;
int arr[1005][1005];

void upd(int x1, int y1, int x2, int y2) {
    ++arr[x1][y1];
    --arr[x2 + 1][y1];
    --arr[x1][y2 + 1];
    ++arr[x2 + 1][y2 + 1];
}

int main() {

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int x1, y1, x2, y2;
    for (int i = 1; i <= N; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        ++x1, ++y1;
        upd(x1, y1, x2, y2);
    }
    int ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            ans += (arr[i][j] == K);
        }
    }
    cout << ans << '\n';

}
