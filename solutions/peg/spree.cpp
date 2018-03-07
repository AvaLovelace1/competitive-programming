/*
 Solution to Coding Spree by Ava Pun
 Key concepts: knapsack dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

int N, T;
int V[1001], H[1001];
int dp[1001][1001];

int solve(int n, int hrs) {
    if (hrs == 0 || n >= N) {
        return 0;
    }
    if (dp[n][hrs] == -1) {
        if (hrs < H[n]) {
            dp[n][hrs] = solve(n + 1, hrs);
        } else {
            dp[n][hrs] = max(V[n] + solve(n + 1, hrs - H[n]), solve(n + 1, hrs));
        }
    }
    return dp[n][hrs];
}

int main() {
    
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &V[i], &H[i]);
    }
    
    memset(dp, -1, sizeof dp);
    printf("%d", solve(0, T));
    
    return 0;
    
}
