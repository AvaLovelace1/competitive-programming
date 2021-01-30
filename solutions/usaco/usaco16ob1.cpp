/*
 * Solution to USACO '16 Open B1 - Diamond Collector by Ava Pun
 * Key concepts: implementation, two pointers
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

int N, K;
int arr[1005];

int main() {

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);

    int j = 1;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        while (j <= N && arr[j] - arr[i] <= K) {
            ++j;
        }
        ans = max(ans, j - i);
    }
    cout << ans << '\n';

}
