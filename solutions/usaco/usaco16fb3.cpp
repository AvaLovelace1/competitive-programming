/*
 * Solution to USACO '16 February B3 - Load Balancing by Ava Pun
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
const int MAX = 1e6 + 5;

int N, B;
pii arr[105];
vi xs, ys;

int main() {

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f >> arr[i].s;
        xs.pb(arr[i].f);
        ys.pb(arr[i].s);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int ans = N;
    for (int i = 0; i <= xs.size(); ++i) {
        for (int j = 0; j <= ys.size(); ++j) {
            int x = (i == 0 ? xs[i] - 1 : i == xs.size() ? xs[xs.size() - 1] + 1 : (xs[i] + xs[i - 1]) / 2);
            int y = (j == 0 ? ys[j] - 1 : j == ys.size() ? ys[ys.size() - 1] + 1 : (ys[j] + ys[j - 1]) / 2);

            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            for (int k = 1; k <= N; ++k) {
                if (arr[k].f > x) {
                    if (arr[k].s > y) ++q1;
                    else ++q4;
                } else {
                    if (arr[k].s > y) ++q2;
                    else ++q3;
                }
            }
            int mxQ = max(max(q1, q2), max(q3, q4));
            ans = min(ans, mxQ);
        }
    }
    cout << ans << '\n';

}
