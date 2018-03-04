/*
 ~ Longest Increasing Subsequence Problem ~
 
 What is the longest increasing subsequence in an array?
 
 Time complexity: O(N^2), O(NlogN) (optimized)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

int N;
int arr[MAX];
int dp[MAX];

int lis() {
    
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
    
    return maxN;
}

int lisOptimized() {
    int len = 0;
    for (int i = 1; i <= N; i++) {
        int pos = (int) (lower_bound(dp, dp + len, arr[i]) - dp);
        dp[pos] = arr[i];
        if (pos == len) {
            len++;
        }
    }
    return len;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Length of longest increasing subsequence: %d\n", lis());
    printf("Length of longest increasing subsequence (optimized): %d\n", lisOptimized());
    
    return 0;
    
}
