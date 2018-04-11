/*
 Solution to Joey and Biology by Ava Pun
 Key concepts: dynamic programming, edit distance
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[1001], B[1001];
int dp[1001][1001];

int main() {
    
    scanf("%d%d%s%s", &N, &M, A, B);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else {
                if (i > 0 && j > 0 && A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = INT_MAX;
                    if (i > 0 && j > 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    }
                    if (i >= 1) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                        if (i >= 2) {
                            dp[i][j] = min(dp[i][j], dp[i - 2][j]);
                            if (i >= 3) {
                                dp[i][j] = min(dp[i][j], dp[i - 3][j]);
                            }
                        }
                    }
                    if (j >= 1) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                        if (j >= 2) {
                            dp[i][j] = min(dp[i][j], dp[i][j - 2]);
                            if (j >= 3) {
                                dp[i][j] = min(dp[i][j], dp[i][j - 3]);
                            }
                        }
                    }
                    dp[i][j]++;
                }
            }
        }
    }
    
    printf("%d", dp[N][M]);
    
    return 0;
}
