/*
 * Solution to Coin Stacks by Ava Pun
 * Key concepts: greedy algorithms, simulation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
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
const int MAX = 55;

int N;
int arr[MAX];

pii getMxs() {
    int i = (int) (max_element(arr + 1, arr + N + 1) - arr);
    int j = 0;
    REP(k, 1, N) {
        if (k != i && arr[k] > arr[j]) {
            j = k;
        }
    }
    return {i, j};
}

void solve() {
    int tot = accumulate(arr + 1, arr + N + 1, 0);
    while (tot > 0) {
        pii mxs = getMxs();
        cout << mxs.f << ' ' << mxs.s << '\n';
        arr[mxs.f]--;
        arr[mxs.s]--;
        tot -= 2;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    int tot = 0;
    int mx = 0;
    REP(i, 1, N) {
        cin >> arr[i];
        tot += arr[i];
        mx = max(mx, arr[i]);
    }

    if (tot - mx < mx) {
        cout << "no\n";
    } else if (tot % 2 == 0) {
        cout << "yes\n";
        solve();
    } else {
        cout << "no\n";
    }
}
