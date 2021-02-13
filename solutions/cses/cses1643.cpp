/*
 * Solution to Maximum Subarray Sum by Ava Pun
 * Key concepts: prefix sum array
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
const int MAX = 2e5 + 5;

int N;
ll arr[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll ans = -INFL;
    ll mn = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, arr[i] - mn);
        mn = min(mn, arr[i]);
    }
    cout << ans << '\n';
}
