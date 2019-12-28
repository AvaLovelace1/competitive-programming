/*
 Solution to Santa's Bot by Ava Pun
 Key concepts: math, combinatorics, number theory, probability
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MAX = 1e6 + 5;
const int MAXL = 17;

int N;
vi arr[MAX];
int numChildren[MAX];
pair<ll, ll> prob[MAX];

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b % 2 == 1) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }
}

ll inv(ll x) {
    return modPow(x % MOD, MOD - 2);
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int k, a;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            arr[i].pb(a);
            numChildren[a]++;
        }
    }

    ll num = 0, denInv = 1, den = 1;
    for (int x = 1; x <= N; x++) {
        for (auto y : arr[x]) {
            prob[x].f += numChildren[y];
            prob[x].s += N;
        }
    }
    for (int x = 1; x <= N; x++) {
        den = den * (prob[x].s % MOD) % MOD;
        denInv = denInv * inv(prob[x].s) % MOD;
    }
    for (int x = 1; x <= N; x++) {
        num += (prob[x].f % MOD) * den % MOD * inv(prob[x].s) % MOD;
        num %= MOD;
    }
    
    den = (den * N) % MOD;
    denInv = (denInv * inv(N)) % MOD;
    printf("%lld\n", num * denInv % MOD);

    return 0;
}
