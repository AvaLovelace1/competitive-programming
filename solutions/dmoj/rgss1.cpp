/*
 Solution to P1 - HSIUNG by Ava Pun
 Key concepts: knapsack dynamic programming
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
const int MAX = 1e6 + 5;

int A, B, C;
bool dp[1005];

int main() {
    
    scanf("%d%d%d", &A, &B, &C);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= C; i++) {
        if (i - A >= 0) {
            dp[i] |= dp[i - A];
        }
        if (i - B >= 0) {
            dp[i] |= dp[i - B];
        }
        if (dp[i]) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
