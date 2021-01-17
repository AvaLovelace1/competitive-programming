/*
 * Solution to USACO '19 January S3 - Mountain View by Ava Pun
 * Key concepts: sorting
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

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int x, y;
    for (int i = 1; i <= N; ++i) {
        cin >> x >> y;
        arr[i] = {x - y, -(x + y)};
    }
    sort(arr + 1, arr + N + 1);
    
    int hidden = 0;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (-arr[i].s > hidden) {
            ++ans;
        }
        hidden = max(hidden, -arr[i].s);
    }
    cout << ans << '\n';

}
