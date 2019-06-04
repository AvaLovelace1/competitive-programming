/*
 Solution to 10229 - Modular Fibonacci by Ava Pun
 Key concepts: matrix exponentiation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, M;
ll mat[2][2] = {{0, 1}, {1, 1}}, tmp[2][2], ans[2][2];

void mult(ll mat[2][2], ll ans[2][2], ll tmp[2][2]) {
    tmp[0][0] = tmp[1][0] = tmp[0][1] = tmp[1][1] = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tmp[i][j] += ans[i][k] * mat[k][j] % M;
                tmp[i][j] %= M;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans[i][j] = tmp[i][j];
        }
    }
}

void matExp(int n) {
    if (n == 0) {
        ans[0][0] = ans[1][1] = 1;
        ans[0][1] = ans[1][0] = 0;
    } else {
        matExp(n / 2);
        mult(ans, ans, tmp);
        if (n & 1) {
            mult(mat, ans, tmp);
        }
    }
}

int main() {

    while (scanf("%d%d", &N, &M) != EOF) {
        M = (int) pow(2, M);
        matExp(N);
        printf("%lld\n", ans[0][1]);
    }

    return 0;
}
