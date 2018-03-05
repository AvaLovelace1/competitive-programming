/*
 Solution to DMOPC '14 Contest 3 P6 - Not Enough Time! by Ava Pun
 Key concepts: knapsack dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

int N, T;
int v[2001][3];
int t[2001][3];
int dp[10001];

int main() {
    
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d%d", &t[i][j], &v[i][j]);
        }
    }
    
    dp[0] = 0;
    for (int j = 1; j <= N; j++) {
        for (int i = T; i >= 0; i--) {
            for (int k = 0; k < 3; k++) {
                if (i >= t[j][k]) {
                    dp[i] = max(dp[i], dp[i - t[j][k]] + v[j][k]);
                }
            }
        }
    }
    
    printf("%d", dp[T]);
    
    return 0;
}
