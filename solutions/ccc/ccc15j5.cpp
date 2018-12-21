/*
 Solution to CCC '15 J5 - π-day by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int nPieces, nPeople;
int dp[251][251];

int numberWays(int i, int j) {
    if (dp[i][j] == -1) {
        if (i == j || j == 1 ) {
            dp[i][j] = 1;
        } else if (i < j) {
            dp[i][j] = 0;
        } else {
            dp[i][j] = numberWays(i - 1, j - 1) + numberWays(i - j, j);
        }
    }
    return dp[i][j];
}

int main() {
    
    scanf("%d%d", &nPieces, &nPeople);
    memset(dp, -1, sizeof dp);
    printf("%d", numberWays(nPieces, nPeople));
    
    return 0;
}
