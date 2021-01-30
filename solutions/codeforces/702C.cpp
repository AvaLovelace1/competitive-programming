/*
 * Solution to Cellular Network by Ava Pun
 * Key concepts: binary search, implementation
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
const int MAX = 1e5 + 2;

int N, M;
int arr1[MAX];
int arr2[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> arr1[i];
    }
    for (int i = 1; i <= M; ++i) {
        cin >> arr2[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        auto it = upper_bound(arr2 + 1, arr2 + M + 1, arr1[i]);
        int closest = INT_MAX;
        if (it != arr2 + 1) {
            closest = min(closest, abs(arr1[i] - *(it - 1)));
        }
        if (it != arr2 + M + 1) {
            closest = min(closest, abs(arr1[i] - *it));
        }
        ans = max(ans, closest);
    }
    cout << ans << '\n';

}
