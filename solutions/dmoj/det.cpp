/*
 Solution to Matrix Determinant by Ava Pun
 Key concepts: matrices, Gaussian elimination
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MOD = 1e9 + 7;
int N;
ll A[501][501];

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

ll calc() {
    
    ll det = 1;
    for (int i = 0; i < N; i++) {
        int maxN = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j][i] > A[maxN][i]) {
                maxN = j;
            }
        }
        if (maxN != i) {
            swap(A[i], A[maxN]);
            det = -det;
        }
        for (int j = i + 1; j < N; j++) {
            ll x = A[j][i] * power(A[i][i], MOD - 2) % MOD;
            for (int k = i; k < N; k++) {
                A[j][k] -= x * A[i][k];
                A[j][k] %= MOD;
                A[j][k] = (A[j][k] + MOD) % MOD;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        det *= A[i][i];
        det %= MOD;
    }
    det = (det + MOD) % MOD;
    
    return det;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lld", &A[i][j]);
            if (A[i][j] < 0) {
                A[i][j] += MOD;
            }
        }
    }
    
    printf("%lld", calc());
    
    return 0;
    
}
