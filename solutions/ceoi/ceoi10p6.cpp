/*
 * Solution to CEOI '10 P6 - A Huge Tower by Ava Pun
 * Key concepts: dynamic programming, sorting, two pointers
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
const int MOD = 1e9 + 9;
const double EPS = 1e-9;
const int MAX = 1e6 + 5;

int N;
ll D;
ll arr[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> D;
    REP(i, 1, N) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);

    ll ans = 1;
    int j = 1;
    REP(i, 1, N) {
        while (arr[j] < arr[i] - D) ++j;
        int possiblePosns = i - j + 1;
        ans = ans * possiblePosns % MOD;
    }
    cout << ans << '\n';

}
