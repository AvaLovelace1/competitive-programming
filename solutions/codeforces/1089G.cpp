/*
 * Solution to Guest Student by Ava Pun
 * Key concepts: implementation, math
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

int T, K;
int arr[7];

int daysReqd(int k) {
    if (k == 0) return 0;
    int tot = 0;
    REP(i, 0, 6) {
        tot += arr[i];
        if (tot == k) return i + 1;
    }
    return -1;
}

int check(int k) {
    int perWeek = accumulate(arr, arr + 7, 0);
    int fullWeeks = (k + perWeek - 1) / perWeek - 1;
    int dFullWeeks = 7 * fullWeeks;
    int dLastWeek = daysReqd(k - perWeek * fullWeeks);
    return dFullWeeks + dLastWeek;
}

void cycle() {
    int tmp = arr[0];
    REP(i, 0, 5) {
        arr[i] = arr[i + 1];
    }
    arr[6] = tmp;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(test, 1, T) {
        cin >> K;
        REP(i, 0, 6) {
            cin >> arr[i];
        }
        int ans = INT_MAX;
        REP(i, 0, 6) {
            ans = min(ans, check(K));
            cycle();
        }
        cout << ans << '\n';
    }

}

