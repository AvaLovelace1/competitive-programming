/*
 Solution to Simon and Marcy by Ava Pun
 Key concepts: knapsack dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int N, C;
int v[1001], w[1001];
int dp[1001];

int main() {
    
    scanf("%d%d", &N, &C);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &v[i], &w[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = C; j >= w[i]; j--) {
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
        }
    }
    
    printf("%d", dp[C]);
    
    return 0;
}
