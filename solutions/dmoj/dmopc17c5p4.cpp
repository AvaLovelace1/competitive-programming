/*
 Solution to DMOPC '17 Contest 5 P4 - Intersecting Arcs by Ava Pun
 Key concepts: dynamic programming, prefix sum array
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
const int MOD = 1e9 + 7;
const int MAX = 505;

int N, K;
int dp[2][MAX][MAX];

int query(int i, int j, int l, int r) {
    if (j < 0) {
        return 0;
    }
    l = max(l, 0), r = max(r, 0);
    if (l == 0) {
        return dp[i][j][r];
    } else {
        return (dp[i][j][r] - dp[i][j][l - 1] + MOD) % MOD;
    }
}

int main() {
    
    scanf("%d%d", &N, &K);
    
    for (int i = 0; i <= N; i++) {
        int i0 = i % 2;
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= K; k++) {
                int &ans = dp[i0][j][k];
                if (i == 0) {
                    if (j == 0 && k == 0) {
                        ans = 1;
                    } else {
                        ans = 0;
                    }
                } else if (j > i) {
                    ans = 0;
                } else {
                    ans = ((query(i0 ^ 1, j, k, k) + query(i0 ^ 1, j - 1, k, k)) % MOD + query(i0 ^ 1, j + 1, k - j, k)) % MOD;
                }
                if (k > 0) {
                    ans += dp[i0][j][k - 1];
                    ans %= MOD;
                }
            }
        }
    }

    printf("%d\n", query(N % 2, 0, K, K));
    
    return 0;
}
