/*
 * Solution to USACO '20 December B2 - Daisy Chains by Ava Pun
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

int N;
int arr[1005];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            int tot = accumulate(arr + i, arr + j + 1, 0);
            for (int k = i; k <= j; ++k) {
                if (arr[k] * (j - i + 1) == tot) {
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';

}
