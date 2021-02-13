/*
 * Solution to Books by Ava Pun
 * Key concepts: two pointers
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

int N, T;
int arr[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    int tot = 0;
    int j = 1;
    for (int i = 1; i <= N; ++i) {
        tot -= arr[i - 1];
        while (j <= N && tot + arr[j] <= T) {
            tot += arr[j];
            ++j;
        }
        ans = max(ans, j - i);
    }
    cout << ans << '\n';

}
