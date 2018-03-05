/*
 Solution to Maximum Sum by Ava Pun
 Key concepts: dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
int dp[100005];

int solve(int i) {
    
    if (i <= 0) {
        return 0;
    }
    
    if (dp[i] == -1) {
            dp[i] = max(solve(i - 1), solve(i - 2) + arr[i]);
    }
    return dp[i];
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", solve(N));
    
    return 0;
}
