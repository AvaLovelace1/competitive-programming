/*
 Solution to CCO Preparation Test 2 - Concatenation by Ava Pun
 Key concepts: matrix exponentation
 */

#include <bits/stdc++.h>

using namespace std;

#define FILL(a, b) memset(a, b, sizeof(a))

typedef unsigned long long int ll;

ll N, M;
int maxDigits;
ll powers[20];
ll init[3] = {0, 0, 1};
ll mat[3][3] = { {0, 1, 1}, {0, 1, 1}, {0, 0, 1} };
ll tmp[3][3], ret[3][3];

inline void matMult(ll a[3][3], ll b[3][3]) {
    FILL(ret, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ret[i][j] += a[i][k] * b[k][j] % M;
                ret[i][j] %= M;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = ret[i][j];
        }
    }
}

void matExp(ll n) {
    if (n == 0) {
        FILL(tmp, 0);
        for (int i = 0; i < 3; i++) {
            tmp[i][i] = 1;
        }
    } else {
        matExp(n / 2);
        matMult(tmp, tmp);
        if (n & 1) {
            matMult(tmp, mat);
        }
    }
}

inline ll solve(int d) {
    matExp(min(N, powers[d] - 1) - powers[d - 1] + 1);
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += tmp[0][i] * init[i] % M;
        ans %= M;
    }
    return ans;
}

int main() {
    
    scanf("%llu%llu", &N, &M);
    maxDigits = log10(N) + 1;
    powers[0] = 1;
    for (int i = 1; i <= 19; i++) {
        powers[i] = powers[i - 1] * 10;
    }
    ll ans = 0;
    for (int i = 1; i <= maxDigits; i++) {
        mat[0][0] = powers[i] % M;
        init[0] = ans;
        init[1] = ((ll) powers[i - 1] - 1) % M;
        ans = solve(i);
    }
    printf("%llu\n", ans);
    
    return 0;
}
