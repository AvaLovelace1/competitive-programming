/*
 Solution to COCI '17 Contest 4 #3 Automobil by Ava Pun
 Key concepts: simple math
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll N, M, K;
map<ll, ll> rows, cols;

int main() {

    scanf("%lld%lld%lld", &N, &M, &K);
    char c;
    ll x, y;
    for (int i = 1; i <= K; i++) {
        scanf(" %c%lld%lld", &c, &x, &y);
        if (c == 'R') {
            if (rows.find(x) == rows.end()) {
                rows[x] = 1;
            }
            rows[x] = rows[x] * y % MOD;
        } else {
            if (cols.find(x) == cols.end()) {
                cols[x] = 1;
            }
            cols[x] = cols[x] * y % MOD;
        }
    }

    ll rowSum = M * (M + 1) / 2 % MOD;
    ll colSum = 0;
    for (ll i = 1; i <= N; i++) {
        colSum = (colSum + i * M % MOD) % MOD;
    }

    ll ans = 0, tmp = 0;
    for (ll i = 1; i <= N; i++) {
        tmp = (rowSum + M * M % MOD * (i - 1) % MOD) % MOD;
        tmp = tmp * (rows.find(i) == rows.end() ? 1 : rows[i]) % MOD;
        ans = (ans + tmp) % MOD;
    }

    for (auto col : cols) {
        ll prevCol = (colSum - (M - col.f) * N % MOD + MOD) % MOD;
        for (auto row : rows) {
            ll n = (M * (row.f - 1) % MOD + col.f) % MOD;
            prevCol = (prevCol + (n * row.s % MOD - n + MOD) % MOD) % MOD;
        }
        tmp = prevCol * col.s % MOD;
        ans = (ans + (tmp - prevCol + MOD) % MOD) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
