/*
 ~ Fast Power Algorithm ~
 
 Calculates an exponent in log b time.
 
 Time complexity: O(logN)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll N, M;

ll power(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else {
        ll ans = power(a * a, b / 2);
        if (b % 2 == 1) {
            ans *= a;
        }
        return ans;
    }
}

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

int main() {
    
    scanf("%lld%lld", &N, &M);
    printf("%lld\n", power(N, M));
    
    return 0;
    
}
