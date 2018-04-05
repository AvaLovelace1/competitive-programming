/*
 Solution to TLE '15 P5 - Prefix Sum Array by Ava Pun
 Key concepts: math
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MOD = 1e9 + 7;
int N, M;
int arr[2001];
ll coeff[2001];
int ans[2001];

ll power(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else {
        ll ans = power(a * a % MOD, b / 2);
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    M--;
    
    coeff[0] = 1;
    for (int i = 1; i < N; i++) {
        coeff[i] = coeff[i - 1] * (M + i) % MOD * power(i, MOD - 2) % MOD;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j + i < N; j++) {
            ans[j + i] += arr[i] * coeff[j] % MOD;
            ans[j + i] %= MOD;
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
    
}
