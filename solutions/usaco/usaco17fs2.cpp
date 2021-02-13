/*
 * Solution to USACO '17 February S2 - Why Did the Cow Cross the Road II by Ava Pun
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
const int MAX = 1e5 + 2;

int N, K, B;
int arr[MAX];

int main() {

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> B;
    int x;
    for (int i = 1; i <= B; ++i) {
        cin >> x;
        arr[x] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        arr[i] += arr[i - 1];
    }
    int ans = N;
    for (int i = 1; i + K - 1 <= N; ++i) {
        int r = i + K - 1;
        int l = i;
        ans = min(ans, arr[r] - arr[l - 1]);
    }
    cout << ans << '\n';
    
}
