/*
 Solution to Valentine's Day '18 S3 - Carol's Cactesian Conquest by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int N, K;
int choose[105][105];
ll dp1[105], dp2[105][105];

ll solve2(int n, int k);

ll solve1(int n) {
    if (dp1[n] == -1) {
        if (n == 0) {
            dp1[n] = 1;
        } else {
            dp1[n] = 0;
            for (int i = 1; i <= n; i++) {
                ll l = (solve1(i - 1) - solve2(i - 1, K) + MOD) % MOD;
                ll r = solve1(n - i);
                dp1[n] += l * r % MOD * choose[n - 1][i - 1] % MOD;
                dp1[n] %= MOD;
            }
        }
    }
    return dp1[n];
}

ll solve2(int n, int k) {
    if (dp2[n][k] == -1) {
        if (k > n) {
            dp2[n][k] = 0;
        } else if (n == 0) {
            dp2[n][k] = 1;
        } else if (k == 0) {
            dp2[n][k] = 0;
        } else {
            dp2[n][k] = solve2(n - 1, k - 1);
            for (int i = 1; i <= n - k; i++) {
                ll l = (solve1(i - 1) - solve2(i - 1, K) + MOD) % MOD;
                ll r = solve2(n - i, k);
                dp2[n][k] += l * r % MOD * choose[n - 1][i - 1] % MOD;
                dp2[n][k] %= MOD;
            }
        }
    }
    return dp2[n][k];
}

ll solve(int n) {
    FILL(dp1, -1);
    FILL(dp2, -1);
    return solve1(n);
}

int main() {
    
    scanf("%d%d", &N, &K);
    
    for (int i = 0; i <= N; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;
        }
    }
    
    ll ans1 = solve(N);
    K--;
    ll ans2 = solve(N);
    printf("%lld\n", (ans1 - ans2 + MOD) % MOD);
    
    return 0;
}
