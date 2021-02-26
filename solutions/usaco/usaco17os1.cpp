/*
 * Solution to USACO '17 Open S1 - Paired Up by Ava Pun
 * Key concepts: two pointers, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 5;

int N;
pii arr[MAX];

int main() {

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i].s >> arr[i].f;
    }
    sort(arr + 1, arr + N + 1);

    int i = 1, j = N;
    int ans = 0;
    while(true) {
        if (j < i) {
            break;
        }
        if (j == i) {
            ans = max(ans, 2 * arr[i].f);
            arr[i].s = 0;
            ++i;
            --j;
        } else {
            ans = max(ans, arr[i].f + arr[j].f);
            int sub = min(arr[i].s, arr[j].s);
            arr[i].s -= sub;
            arr[j].s -= sub;
            if (arr[i].s == 0) ++i;
            if (arr[j].s == 0) --j;
        }
    }
    cout << ans << '\n';

}

