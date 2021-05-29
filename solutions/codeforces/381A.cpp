/*
 * Solution to Sereja and Dima by Ava Pun
 * Key concepts: implementation, two pointers
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
const int MAX = 2e5 + 5;

int N;
int arr[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i];
    }
    int l = 1, r = N;
    int ans[2] = {};
    bool p = 0;
    while (l <= r) {
        if (arr[l] > arr[r]) ans[p] += arr[l], ++l;
        else ans[p] += arr[r], --r;
        p = !p;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';

}
