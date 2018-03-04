/*
 Solution to CCC '00 S4 - Golf by Ava Pun
 Key concepts: dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3F3F3F3F;

int N, M;
int arr[33];
int dp[5285];

int solve(int n) {
    
    if (n > N) {
        return INF;
    }
    
    if (dp[n] == -1) {
        if (n == N) {
            dp[n] = 0;
        } else {
            int ans = INF;
            for (int i = 0; i < M; i++) {
                ans = min(ans, 1 + solve(n + arr[i]));
            }
            dp[n] = ans;
        }
    }
    
    return dp[n];
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &arr[i]);
    }
    fill(dp, dp + N + 1, -1);
    int ans = solve(0);
    if (ans == INF) {
        printf("Roberta acknowledges defeat.");
    } else {
        printf("Roberta wins in %d strokes.", ans);
    }
    
    return 0;
    
}
