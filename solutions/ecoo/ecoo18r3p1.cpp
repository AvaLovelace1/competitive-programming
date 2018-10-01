/*
 Solution to ECOO '18 R3 P1 - Balanced by Ava Pun
 Key concepts: combinatorics
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

int B, G;

inline ll fact(int n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i % MOD;
    }
    return ans;
} 

ll modPow(ll a, int b) {
    if (b == 0) {
        return 1;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ans = ans * a % MOD;
        }
        return ans;
    }
}

inline ll choose(int n, int k) {
    return fact(n) * modPow(fact(n - k), MOD - 2) % MOD * modPow(fact(k), MOD - 2) % MOD;
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d%d", &B, &G);
        if (G == 1) {
            printf("0\n");
        } else {
            ll ans = 0;
            for (int i = 0; i * (G - 1) <= B; i += 2) {
                ans += B - i * (G - 1) + 1;
                ans %= MOD;
            }
            ans = (choose(B + G, G) - ans + MOD) % MOD;
            ans = ans * fact(B) % MOD;
            ans = ans * fact(G) % MOD;
            printf("%lld\n", ans);
        }
    }

    return 0;
}
