/*
 * Solution to Devu, the Singer and Churu, the Joker by Ava Pun
 * Key concepts: greedy algorithms, implementation
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

int N, D;
int arr[105];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> D;
    REP(i, 1, N) {
        cin >> arr[i];
    }

    int tot = accumulate(arr + 1, arr + N + 1, 0) + 10 * (N - 1);
    if (tot > D) cout << "-1\n";
    else {
        int rem = D - tot;
        int ans = 2 * (N - 1) + rem / 5;
        cout << ans << '\n';
    }

}

