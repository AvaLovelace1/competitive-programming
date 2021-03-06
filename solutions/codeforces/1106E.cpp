/*
 * Solution to Lunar New Year and Red Envelopes by Ava Pun
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

int N, M, K;
struct Red {
    int a, b, d, w;
} arr[MAX];
vi on[MAX], off[MAX];

int which[MAX];
ll dp[2][MAX];

bool comp(int a, int b) {
    if (arr[a].w == arr[b].w) {
        if (arr[a].d == arr[b].d) {
            return a < b;
        }
        return arr[a].d > arr[b].d;
    }
    return arr[a].w > arr[b].w;
}

void calcWhich() {
    set<int, decltype(comp)*> ss(comp);
    REP(i, 1, N) {
        TRAV(j, on[i]) {
            ss.insert(j);
        }
        which[i] = ss.empty() ? 0 : *ss.begin();
        TRAV(j, off[i]) {
            ss.erase(j);
        }
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> K;
    REP(i, 1, K) {
        int a, b, d, w;
        cin >> a >> b >> d >> w;
        arr[i] = Red{a, b, d, w};
        on[a].pb(i);
        off[b].pb(i);
    }

    calcWhich();

    FILL(dp, INF);
    REP(i, 0, M) {
        dp[i % 2][N + 1] = 0;
        REV(j, N, 1) {
            ll &cur = dp[i % 2][j];
            if (which[j] == 0) {
                cur = dp[i % 2][j + 1];
            } else {
                auto &red = arr[which[j]];
                ll take = dp[!(i % 2)][j + 1];
                ll dont = dp[i % 2][red.d + 1] + red.w;
                cur = min(take, dont);
            }
        }
    }

    ll ans = dp[M % 2][1];
    cout << ans << '\n';

}

