/*
 * Solution to Glass Half Spilled by Ava Pun
 * Key concepts: dynamic programming
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
int arr[105], brr[105];
int dp[2][105][10005];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i] >> brr[i];
    }

    FILL(dp, -INF);
    dp[0][0][0] = 0;
    REP(i, 1, N) {
        REP(j, 0, i) {
            REP(k, 0, j * 100) {
                int pick = -INF;
                if (j - 1 >= 0 && k - arr[i] >= 0) {
                    pick = dp[!(i % 2)][j - 1][k - arr[i]] + brr[i];
                }
                int dont = dp[!(i % 2)][j][k];
                dp[i % 2][j][k] = max(pick, dont);
            }
        }
    }

    int sumBAll = accumulate(brr + 1, brr + N + 1, 0);
    REP(j, 1, N) {
        double ans = 0;
        REP(k, 0, j * 100) {
            ans = max(ans, min((double) k, (double) (sumBAll + dp[N % 2][j][k]) / 2.0));
        }
        cout << ans << " \n"[j == N];
    }

}

