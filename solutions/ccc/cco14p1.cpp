/*
 Solution to CCO '14 P1 - Troyangles by Ava Pun
 Key concepts: dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;

int N;
char grid[MAX][MAX];
int dp[MAX][MAX];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%s", grid[i] + 1);
    }
    
    int ans = 0;
    for (int i = N; i >= 0; i--) {
        for (int j = 0; j <= N; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if (grid[i][j] == '#') {
                    dp[i][j] = 1 + min(min(dp[i + 1][j + 1], dp[i + 1][j - 1]), dp[i + 1][j]);
                }
                ans += dp[i][j];
            }
        }
    }
    printf("%d", ans);
    
    return 0;
}
