/*
 Solution to TLE '15 P4 - Olympiads Homework by Ava Pun
 Key concepts: math
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MOD = 1e9 + 13;
ll N;

ll power(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else {
        ll ans = power(a * a % MOD, b / 2);
        if (b % 2) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }
}

int main() {

    scanf("%lld", &N);
    ll ans = power(2, N - 2);
    int quad = N % 8;
    if (quad == 2 || quad == 6) {
        quad = 0;
    } else if (quad >= 3 && quad <= 6){
        quad = -1;
    } else {
        quad = 1;
    }
    if (N == 1) {
        ans = 1;
    } else {
        ans += power(2, (N / 2) - 1) * quad;
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
    }
    
    printf("%lld", ans);
    
    return 0;
    
}
