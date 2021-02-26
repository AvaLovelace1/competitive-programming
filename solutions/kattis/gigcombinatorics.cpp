/*
 * Solution to Gig Combinatorics by Ava Pun
 * Key concepts: combinatorics
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
const int MAX = 1e6 + 5;

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

    int cnt = 0;
    int tot = 0;
    int ans = 0;
    REP(i, 1, N) {
        if (arr[i] == 1) {
            ++cnt;
            ++tot;
            tot %= MOD;
        } else if (arr[i] == 2) {
            tot *= 2;
            tot %= MOD;
        } else {
            ans += tot - cnt;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
    }
    cout << ans << '\n';

}

