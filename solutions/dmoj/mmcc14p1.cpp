/*
 Solution to Tenri by Ava Pun
 Key concepts: bitmask dynamic programming
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
const int MAX = 1e5 + 5;

int N, S;
int arr[12];
int dp[(1 << 11) + 5][16];
vector<pii> subsets[(1 << 11) + 5];

int main() {
    
    scanf("%d%d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }    
    
    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) % 2 == 0) {
            for (int j = 1; j < i; j++) {
                if (!(~i & j) && __builtin_popcount(j) % 2 == 1) {
                    int k = i & ~j;
                    if (j <= k && __builtin_popcount(k) % 2 == 1) {
                        subsets[i].pb({j, k});
                    }
                }
            }
        }
    }
    
    for (int m = 0; m < (1 << N); m++) {
        for (int k = 0; k <= S; k++) {
            if (__builtin_popcount(m) == 1) {
                int n = __builtin_ctz(m);
                dp[m][k] = (arr[n] + k) * (arr[n] + k) + k;
            } else {
                for (int n = 0; n < N; n++) {
                    if (m & (1 << n)) {
                        for (pii p : subsets[m & ~(1 << n)]) {
                            for (int i = 0; i <= k; i++) {
                                for (int j = 0; i + j <= k; j++) {
                                    int k1 = k - i - j;
                                    dp[m][k] = max(dp[m][k], min(dp[p.f][i] * dp[p.s][j], (int) (arr[n] + k1) * (arr[n] + k1)) + k1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[(1 << N) - 1][S]);
    
    return 0;
}
