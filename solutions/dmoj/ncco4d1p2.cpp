/*
 Solution to Mock CCO '18 Contest 4 Problem 2 - Sunken Colonies by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e8;
const int MAX = 20e3 + 5;

int R, C;
int arr[13];
int dp[13][(1 << 12) + 5];
vi masks;

int main() {
    
    scanf("%d%d", &R, &C);
    int n;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &n);
            arr[i] <<= 1;
            arr[i] |= n;
        }
    }
    
    for (int m = 0; m < (1 << C); m++) {
        bool valid = 1;
        for (int i = 0; i < C - 1 && valid; i++) {
            if ((m & (1 << i)) && (m & (1 << (i + 1)))) {
                valid = 0;
            }
        }
        if (valid) {
            masks.pb(m);
        }
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= R; i++) {
        for (int m : masks) {
            if (!(m & ~arr[i])) {
                for (int m0 : masks) {
                    if (!(m & m0)) {
                        dp[i][m] += dp[i - 1][m0];
                        dp[i][m] %= MOD;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int m : masks) {
        ans += dp[R][m];
        ans %= MOD;
    }
    printf("%d\n", ans);
    
    return 0;
}
