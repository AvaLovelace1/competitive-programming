/*
 Solution to TLE '17 Contest 3 P6 - Donut Coupons by Ava Pun
 Key concepts: binary indexed tree, math
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll FACT = 39916800, DIV;
ll coeffs[11][12] = {
    {0, FACT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, FACT / 2, FACT / 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, FACT / 6, FACT / 2, FACT / 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, FACT / 4, FACT / 2, FACT / 4, 0, 0, 0, 0, 0, 0, 0},
    {0, MOD - FACT / 30, 0, FACT / 3, FACT / 2, FACT / 5, 0, 0, 0, 0, 0, 0},
    {0, 0, MOD - FACT / 12, 0, FACT / 12 * 5, FACT / 2, FACT / 6, 0, 0, 0, 0, 0},
    {0, FACT / 42, 0, MOD - FACT / 6, 0, FACT / 2, FACT / 2, FACT / 7, 0, 0, 0, 0},
    {0, 0, FACT / 12, 0, MOD - FACT / 24 * 7, 0, FACT / 12 * 7, FACT / 2, FACT / 8, 0, 0, 0},
    {0, MOD - FACT / 30, 0, FACT / 9 * 2, 0, MOD - FACT / 15 * 7, 0, FACT / 3 * 2, FACT / 2, FACT / 9, 0, 0},
    {0, 0, MOD - FACT / 20 * 3, 0, FACT / 2, 0, MOD - FACT / 10 * 7, 0, FACT / 4 * 3, FACT / 2, FACT / 10, 0},
    {0, FACT / 66 * 5, 0, MOD - FACT / 2, 0, FACT, 0, MOD - FACT, 0, FACT / 6 * 5, FACT / 2, FACT / 11},
};
int N, Q;
ll bit[12][MAX], updates[12];
int choose[12][12];

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }
}

inline void update(int pos, ll x, ll bit[]) {
    for (int i = pos; i <= N; i += i & -i) {
        bit[i] += x;
        bit[i] %= MOD;
    }
}

inline void updRng(int l, int r, ll x, ll bit[]) {
    update(l, x, bit), update(r + 1, MOD - x, bit);
}

inline void updRng(int l, int r, int k) {
    
    FILL(updates, 0);
    int d = l - 1;
    for (int i = 1; i <= k + 1; i++) {
        updates[i] = coeffs[k][i];
        int mult = -1;
        for (int j = i - 1; j >= 0; j--) {
            updates[j] += (mult * coeffs[k][i] * choose[i][j] % MOD * modPow(d, i - j) % MOD + MOD) % MOD;
            updates[j] %= MOD;
            mult = -mult;
        }
    }
    for (int i = 0; i <= k + 1; i++) {
        updRng(l, r, updates[i], bit[i]);
    }
    
    ll n = r - l + 1, tot = 0;
    for (int i = 1; i <= k + 1; i++) {
        tot += modPow(n, i) * coeffs[k][i] % MOD;
        tot %= MOD;
    }
    update(r + 1, tot, bit[0]);
}

inline ll query(int pos, ll bit[]) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
        ans %= MOD;
    }
    return ans;
}

inline ll querTot(int pos) {
    ll ans = 0;
    for (int i = 0; i <= 11; i++) {
        ans += query(pos, bit[i]) * modPow(pos, i) % MOD;
        ans %= MOD;
    }
    ans *= DIV;
    ans %= MOD;
    return ans;
}

inline ll querTot(int l, int r) {
    return (querTot(r) - querTot(l - 1) + MOD) % MOD;
}

int main() {

    DIV = modPow(FACT, MOD - 2);
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < 12; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;
        }
    }
    
    char c;
    int l, r, k;
    while (Q--) {
        scanf(" %c%d%d", &c, &l, &r);
        if (c == 'U') {
            scanf("%d", &k);
            updRng(l, r, k);
        } else {
            printf("%lld\n", querTot(l, r));
        }
    }
    
    return 0;
}
