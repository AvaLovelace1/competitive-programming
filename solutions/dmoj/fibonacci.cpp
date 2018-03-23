/*
 Solution to Fibonacci Sequence by Ava Pun
 Key concepts: fast matrix exponentiation
 */

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

const ull MOD = 1e9 + 7;
ull N;
ull mat[2][2] = { {0, 1}, {1, 1} };
ull tmp[2][2];
ull ans[2][2];
ull fiboStart[2] = {0, 1};
ull fiboAns[2] = {};

void exp(ull n, int size) {
    
    if (n == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    tmp[i][j] = 1;
                } else {
                    tmp[i][j] = 0;
                }
            }
        }
    } else {
        exp(n / 2, size);
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    ans[i][j] += (tmp[i][k] % MOD) * (tmp[k][j] % MOD);
                    ans[i][j] %= MOD;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tmp[i][j] = ans[i][j];
            }
        }
        
        if (n % 2 != 0) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    ans[i][j] = 0;
                    for (int k = 0; k < size; k++) {
                        ans[i][j] += (tmp[i][k] % MOD) * (mat[k][j] % MOD);
                        ans[i][j] %= MOD;
                    }
                }
            }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    tmp[i][j] = ans[i][j];
                }
            }
        }
    }
}

void mult(int size) {
    
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            fiboAns[i] += (ans[i][k] % MOD) * (fiboStart[k] % MOD);
            fiboAns[i] %= MOD;
        }
    }
}

int main() {
    
    scanf("%llu", &N);
    exp(N, 2);
    mult(2);

    printf("%llu", fiboAns[0]);
    
}
