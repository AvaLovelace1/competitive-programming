/*
 Solution to A Game by Ava Pun
 Key concepts: dynamic programming, prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1005];
int dp[1005][1005];

int solve(int l, int r) {
    if (dp[l][r] == -1) {
        if (l == r) {
            dp[l][r] = arr[r] - arr[l - 1];
        } else {
            dp[l][r] = arr[r] - arr[l - 1] - min(solve(l + 1, r), solve(l, r - 1));
        }
    }
    return dp[l][r];
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    memset(dp, -1, sizeof(dp));
    
    printf("%d", solve(1, N));
    
    return 0;
}
