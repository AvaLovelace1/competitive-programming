/*
 * Solution to USACO '18 Open S1 - Out of Sorts by Ava Pun
 * Key concepts: concepts
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

int N;
pii arr[MAX];

int main() {

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f;
        arr[i].s = i;
    }
    sort(arr + 1, arr + N + 1);

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, arr[i].s - i);
    }
    cout << ans + 1 << '\n';

}
