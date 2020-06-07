/*
 Solution to Memory and Scores by Ava Pun
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
const int MAX = 2 * 1000 * 100 + 100;
const double EPS = 1e-7;

int A, B, K, T;
int SHIFT = MAX + 1;
int dp[100 + 2][2 * MAX + 3];

inline int quer(int pref[], int l, int r) {
    l = max(l, -MAX), r = max(r, -MAX - 1);
    l = min(l, MAX + 1), r = min(r, MAX);
    return (pref[r + SHIFT] - pref[l - 1 + SHIFT] + MOD) % MOD;
}

int main() {
    
    scanf("%d%d%d%d", &A, &B, &K, &T);

    dp[0][A - B + SHIFT] = 1;
    for (int i = 1; i <= T; i++) {
        // compute prefix sums
        for (int j = -MAX; j <= MAX; j++) {
            dp[i - 1][j + SHIFT] += dp[i - 1][j + SHIFT - 1];
            dp[i - 1][j + SHIFT] %= MOD;
        }
        // sliding window
        int tot = 0;
        int l = -MAX - K, r = -MAX - K - 1;
        for (int j = -MAX; j <= MAX; j++) {
            while (r < j + K) {
                r++;
                tot += quer(dp[i - 1], r - K, r + K);
                tot %= MOD;
            }
            while (l < j - K) {
                tot += -quer(dp[i - 1], l - K, l + K) + MOD;
                tot %= MOD;
                l++;
            }
            dp[i][j + SHIFT] = tot;
        }
    }

    int ans = 0;
    for (int i = 1; i <= MAX; i++) {
        ans += dp[T][i + SHIFT];
        ans %= MOD;
    }
    printf("%d\n", ans);

    return 0;
}
