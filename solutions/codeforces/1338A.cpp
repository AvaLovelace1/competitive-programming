/*
 * Solution to Powered Addition by Ava Pun
 * Key concepts: greedy algorithms
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

int T;
int N;
int arr[MAX];

int solve() {
    int ret = 0;
    int prev = arr[1];
    for (int i = 2; i <= N; ++i) {
        if (arr[i] >= prev) {
            prev = arr[i];
        } else {
            int diff = prev - arr[i];
            int mx = sizeof(int) * 8 - __builtin_clz(diff);
            ret = max(ret, mx);
        }
    }
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int test = 1; test <= T; ++test) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> arr[i];
        }
        cout << solve() << '\n';
    }

}
