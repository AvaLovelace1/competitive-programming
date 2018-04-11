/*
 Solution to Pick It by Ava Pun
 Key concepts: interval dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[201];
int dp[201][201];

int solve(int l, int r) {
    if (dp[l][r] == -1) {
        if (l == r) {
            dp[l][r] = arr[l];
        } else {
            dp[l][r] = 0;
            for (int i = l + 1; i < r; i++) {
                dp[l][r] = max(dp[l][r], arr[l] + solve(l, i) + arr[i] + solve(i, r) + arr[r]);
            }
        }
    }
    return dp[l][r];
}

int main() {
    
    scanf("%d", &N);
    while (N) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(1, N));
        
        scanf("%d", &N);
    }
    
    return 0;
}
