/*
 Solution to Inverse Coloring by Ava Pun
 Key concepts: dynamic programming
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
const int MOD = 998244353;
const int MAX = 500 + 5;

int N, K;
int dp1[MAX], dp2[MAX];

inline int query(int l, int r, int pref[]) {
    if (l == 0) {
        return pref[r];
    }
    return (pref[r] - pref[l - 1] + MOD) % MOD;
}

int main() {
    
    scanf("%d%d", &N, &K);
    dp1[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp1[j] = (query(max(0, j - i), j - 1, dp1) + dp1[j - 1]) % MOD;
        }
        dp2[i] = query(N, N, dp1);
    }
    
    for (int i = N; i >= 1; i--) {
        dp2[i] = (dp2[i] - dp2[i - 1] + MOD) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i * j < K) {
                ans += (ll) dp2[i] * dp2[j] % MOD;
                ans %= MOD;
            }
        }
    }
    printf("%lld\n", 2 * ans % MOD);
    
    return 0;
}
