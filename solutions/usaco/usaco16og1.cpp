/*
 * Solution to USACO '16 Open G1 - Splitting the Field by Ava Pun
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
const int MAX = 5e4 + 2;

int N;
pii arr[MAX];

void ins(int x, map<int, int> &mp) {
    ++mp[x];
}

void rem(int x, map<int, int> &mp) {
    --mp[x];
    if (mp[x] == 0) {
        mp.erase(x);
    }
}

ll calc(map<int, int> &xs, map<int, int> &ys) {
    if (xs.empty() || ys.empty()) return 0;
    else {
        return (ll) ((*(--xs.end())).f - (*(xs.begin())).f) * ((*(--ys.end())).f - (*(ys.begin())).f);
    }
}

ll solve() {
    sort(arr + 1, arr + N + 1);
    map<int, int> xsL, xsR, ysL, ysR;
    for (int i = 1; i <= N; ++i) {
        ins(arr[i].f, xsR);
        ins(arr[i].s, ysR);
    }

    ll smallest = INFL;
    ll ans = 0;
    int i = 1;
    while (i <= N) {
        do {
            rem(arr[i].f, xsR);
            rem(arr[i].s, ysR);
            ins(arr[i].f, xsL);
            ins(arr[i].s, ysL);
            ++i;
        } while (i <= N && arr[i] == arr[i - 1]);
        ll tot = calc(xsL, ysL) + calc(xsR, ysR);
        smallest = min(smallest, tot);
        if (i > N) {
            ans = tot - smallest;
        }
    }
    return ans;
}

int main() {

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f >> arr[i].s;
    }
    ll ans = solve();
    for (int i = 1; i <= N; ++i) {
        arr[i] = {arr[i].s, arr[i].f};
    }
    ans = max(ans, solve());

    cout << ans << '\n';

}
