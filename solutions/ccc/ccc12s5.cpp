/*
 Solution to CCC '12 S5 - Mouse Journey by Ava Pun
 Key concepts: dynamic programming
 */
 
 #include <bits/stdc++.h>

using namespace std;

int R, C, K;
int dp[26][26];
bool cat[26][26];

int main() {
    
    scanf("%d%d%d", &R, &C, &K);
    int a, b;
    while (K--) {
        scanf("%d%d", &a, &b);
        cat[a][b] = 1;
    }
    
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0 || cat[i][j]) {
                dp[i][j] = 0;
            } else if (i == 1 && j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    
    printf("%d", dp[R][C]);
    
    return 0;
    
}
