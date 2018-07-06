/*
 Solution to DMOPC '17 Contest 1 P4 - Quests by Ava Pun
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
const int MAX = 5005;

int N, H;
ll dp[2][2][MAX];

int main() {
    
    scanf("%d%d", &N, &H);
    int g, h, q, t;
    for (int i = 1; i <= N; i++) {
        int n = i & 1;
        scanf("%d%d%d%d", &g, &h, &q, &t);
        for (int j = 0; j <= H; j++) {
            dp[n][0][j] = j - h >= 0 ? max(dp[!n][0][j], dp[n][1][j - h] + g) : dp[!n][0][j];
            dp[n][1][j] = j - t >= 0 ? max(dp[!n][0][j], dp[n][1][j - t] + q) : dp[!n][0][j];
        }
    }
    printf("%lld\n", dp[N & 1][0][H]);
    
    return 0;
}
