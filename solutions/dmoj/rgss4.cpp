/*
 Solution to P4 - HEIGHT by Ava Pun
 Key concepts: dynamic programming, maximum increasing subsequence
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main() {
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    dp[0] = arr[0];
    
    int totalMax = dp[0];
    for (int i = 1; i < N; i++) {
        int maxN = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                maxN = max(maxN, dp[j] + arr[i]);
            }
        }
        if (maxN == INT_MIN) {
            dp[i] = arr[i];
        } else {
            dp[i] = maxN;
        }
        totalMax = max(totalMax, dp[i]);
    }
    
    printf("%d", totalMax);
    
    return 0;
    
}
