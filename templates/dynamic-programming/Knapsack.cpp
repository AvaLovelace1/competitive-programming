/*
 ~ Knapsack Problem ~
 
 What is the maximum value obtainable if you have to choose from N items each with a value vi and weight wi
 and your knapsack has a capacity of C?
 Comes in unbounded (can take multiple of each item) and bounded forms.
 
 Time complexity: O(NC)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

int N, C;
int val[MAX], weight[MAX];
int dp[MAX][MAX];
int dp1[MAX];

int knap(bool ub) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            if (ub) {
                if (j - weight[i] >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + val[i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                if (j - weight[i] >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + val[i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[N][C];
}

int knapOptimized(bool ub) {
    // optimized space complexity
    dp1[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (ub) {
            for (int j = 1; j <= C; j++) {
                if (j - weight[i] >= 0) {
                    dp1[j] = max(dp1[j], dp1[j - weight[i]] + val[i]);
                }
            }
        } else {
            for (int j = C; j > 0; j--) {
                if (j - weight[i] >= 0) {
                    dp1[j] = max(dp1[j], dp1[j - weight[i]] + val[i]);
                }
            }
        }
    }
    
    return dp1[C];
}

int main() {
    
    scanf("%d%d", &N, &C);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &val[i], &weight[i]);
    }
    
    printf("Bounded: %d\nUnbounded: %d\n", knap(0), knap(1));
    printf("Bounded optimized: %d\nUnbounded optimized: %d\n", knapOptimized(0), knapOptimized(1));
    
    return 0;
    
}
