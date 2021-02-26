/*
 * Solution to Film Critics by Ava Pun
 * Key concepts: greedy algorithms
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
const int MAX = 2e5 + 5;

int N, M, K;
pii arr[MAX];
int ans[MAX];

void solve() {
    sort(arr + 1, arr + N + 1);

    int border = N - (K / M);

    int i = border, j = border + 1;
    int totScore = 0;
    int critics = 0;
    while (critics < N) {
        if (j <= N && totScore <= arr[j].f * critics) {
            totScore += M;
            ++critics;
            ans[critics] = arr[j].s;
            ++j;
        } else if (i >= 1 && totScore > arr[i].f * critics) {
            ++critics;
            ans[critics] = arr[i].s;
            --i;
        } else {
            cout << "impossible\n";
            return;
        }
    }

    REP(i, 1, N) {
        cout << ans[i] << " \n"[i == N];
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> K;
    REP(i, 1, N) {
        cin >> arr[i].f;
        arr[i].s = i;
    }

    if (K % M != 0 || K / M < 1 || K / M > N) {
        cout << "impossible\n";
    } else {
        solve();
    }

}
