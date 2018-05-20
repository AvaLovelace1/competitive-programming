/*
 Solution to CCO '18 P1 - Geese vs. Hawks by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define FILL(a, b) memset(a, b, sizeof(a))

const int MAX = 1005;

int N;
bool wins[2][MAX];
int arr[2][MAX];
int dp[MAX][MAX];

int solve(int n, int m) {
    if (dp[n][m] == -1) {
        if (n == 0 || m == 0) {
            dp[n][m] = 0;
        } else {
            if (wins[0][n] != wins[1][m] && ((wins[0][n] && arr[0][n] > arr[1][m]) ||
            (!wins[0][n] && arr[0][n] < arr[1][m]))) {
                dp[n][m] = solve(n - 1, m - 1) + arr[0][n] + arr[1][m];
            }
            dp[n][m] = max(dp[n][m], max(solve(n - 1, m), solve(n, m - 1)));
        }
    }
    return dp[n][m];
}

int main() {
    
    scanf("%d", &N);
    char c;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        wins[0][i] = c == 'W';
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[0][i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        wins[1][i] = c == 'W';
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[1][i]);
    }
    
    FILL(dp, -1);
    printf("%d\n", solve(N, N));
    
    return 0;
}
