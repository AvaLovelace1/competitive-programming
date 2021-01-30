/*
 * Solution to USACO '16 February B1 - Milk Pails by Ava Pun
 * Key concepts: brute force, implementation
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

int X, Y, M;

int main() {

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y >> M;

    int ans = 0;
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            if (X * i + Y * j <= M) {
                ans = max(ans, X * i + Y * j);
            }
        }
    }
    cout << ans << '\n';

}
