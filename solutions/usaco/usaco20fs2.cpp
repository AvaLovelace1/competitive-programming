/*
 * Solution to USACO '20 February S2 - Triangles by Ava Pun
 * Key concepts: sorting
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N;
const int M = 20001;
vi xtoy[M + 2];
vi ytox[M + 2];
int totL[M + 2];
ll sumL[M + 2];
int totR[M + 2];
ll sumR[M + 2];
int prevVal[M + 2];

int main() {

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        x += 1e4 + 1;
        y += 1e4 + 1;
        xtoy[x].pb(y);
        ytox[y].pb(x);
    }

    for (int i = 1; i <= M; ++i) {
        totR[i] = (int) ytox[i].size();
        sumR[i] = accumulate(ytox[i].begin(), ytox[i].end(), 0LL) % MOD;
    }

    ll ans = 0;
    for (int x = 1; x <= M; ++x) {

        ll vSumL = 0;
        int vTotL = 0;
        ll vSumR = accumulate(xtoy[x].begin(), xtoy[x].end(), 0LL) % MOD;
        int vTotR = (int) xtoy[x].size();
        int vPrevVal = 0;

        for (int y : xtoy[x]) {
            
            vSumR -= (ll) vTotR * (y - vPrevVal) % MOD;
            vSumR = (vSumR + MOD) % MOD;
            --vTotR;
            vSumL += (ll) vTotL * (y - vPrevVal) % MOD;
            vSumL %= MOD;
            ++vTotL;

            sumR[y] -= (ll) totR[y] * (x - prevVal[y]) % MOD;
            sumR[y] = (sumR[y] + MOD) % MOD;
            --totR[y];
            sumL[y] += (ll) totL[y] * (x - prevVal[y]) % MOD;
            sumL[y] %= MOD;
            ++totL[y];

            ans += (vSumL + vSumR) * (sumL[y] + sumR[y]) % MOD;
            ans %= MOD;

            vPrevVal = y;
            prevVal[y] = x;
        }
    }

    cout << ans << '\n';

}
