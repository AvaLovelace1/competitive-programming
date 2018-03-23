/*
 Solution to Fast Factorial Calculator by Ava Pun
 Key concepts: math
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD = pow(2, 32);
ll N;

int main() {
    
    scanf("%lld", &N);
    while (N--) {
        ll n;
        scanf("%lld", &n);
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= i;
            ans %= MOD;
            if (ans == 0) {
                break;
            }
        }
        printf("%lld\n", ans);
    }
    
    return 0;
    
}
