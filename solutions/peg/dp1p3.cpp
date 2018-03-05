/*
 Solution to Longest Increasing Subsequence by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[5005];
int dp[5005];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int maxN = 0;
    dp[0] = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxN = max(maxN, dp[i]);
    }
    
    printf("%d", maxN);
    
    return 0;
    
}
