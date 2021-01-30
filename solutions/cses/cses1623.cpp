/*
 * Solution to Apple Division by Ava Pun
 * Key concepts: bitmask brute force
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
const int MAX = 2e5 + 2;

int N;
ll arr[22];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    ll ans = INFL;
    for (int m = 0; m < (1 << N); ++m) {
        ll l = 0, r = 0;
        for (int i = 0; i < N; ++i) {
            if (m & (1 << i)) {
                l += arr[i];
            } else {
                r += arr[i];
            }
        }
        ans = min(ans, abs(l - r));
    }
    cout << ans << '\n';

}
