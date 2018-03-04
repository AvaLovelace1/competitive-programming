/*
 Solution to IOI '94 P1 - The Triangle by Ava Pun
 Key concepts: dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

int N;
int dp[101][101];

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &n);
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + n;
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[N][i]);
    }
    printf("%d", ans);
    
    return 0;
}
