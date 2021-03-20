/*
 Solution to DMOPC '20 Contest 1 P4 - Victor Makes Bank by Ava Pun
 Key concepts: matrix multiplication
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
const int MAX = 1e5 + 5;

ll N, K, F;
int T;
ll mat[105][105];
ll tmp[105][105], ans[105][105];
ll fiboStart[105];
ll fiboAns[105];

inline void mult(ll a[][105], ll b[][105], ll c[][105], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = 0;
            for (int k = 0; k < size; k++) {
                c[i][j] += a[i][k] * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = c[i][j];
        }
    }
}

void exp(ll n, int size) {
    if (n == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    ans[i][j] = tmp[i][j] = 1;
                } else {
                    ans[i][j] = tmp[i][j] = 0;
                }
            }
        }
    } else {
        exp(n / 2, size);
        mult(tmp, tmp, ans, size);
        if (n % 2 != 0) {
            mult(tmp, mat, ans, size);
        }
    }
}

inline void solve(ll n, int size) {
    exp(n, size);
    for (int i = 0; i < size; i++) {
        fiboAns[i] = 0;
        for (int k = 0; k < size; k++) {
            fiboAns[i] += ans[i][k] * fiboStart[k] % MOD;
            fiboAns[i] %= MOD;
        }
    }
}

int main() {
    
    scanf("%lld%lld%d%lld", &N, &K, &T, &F);
    for (int i = 0; i <= T; i++) {
        fiboStart[i] = F;
    }
    for (int i = 0; i < T; i++) {
        mat[i][i + 1] = 1;
    }
    mat[T][T] = 1;
    mat[T][0] = K;
    
    solve(N - 1, T + 1);
    ll adults = fiboAns[0];
    ll babies = (fiboAns[T] - adults + MOD) % MOD;
    printf("%lld\n", (adults * 2 % MOD + babies) % MOD);
    
    return 0;
}
