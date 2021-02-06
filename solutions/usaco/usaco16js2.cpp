/*
 * Solution to USACO '16 January S2 - Subsequences Summing to Sevens by Ava Pun
 * Key concepts: prefix sum array, mathematics, modular arithmetic
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

int N;
int arr[MAX];
int idx[7];

int main() {

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        arr[i] %= 7;
        if (idx[arr[i]] == 0) {
            idx[arr[i]] = i;
        }
        if (idx[arr[i]] != 0) {
            ans = max(ans, i - idx[arr[i]]);
        }
    }

    cout << ans << '\n';
    
}
