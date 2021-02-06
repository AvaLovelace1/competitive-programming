/*
 * Solution to Subarray Sums II by Ava Pun
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
const int MAX = 2e5 + 2;

int N, X;
ll arr[MAX];
map<ll, int> mp;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> X;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    ll ans = 0;
    mp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        ll diff = arr[i] - X;
        ans += mp[diff];
        mp[arr[i]]++;
    }
    cout << ans << '\n';
    
}
