/*
 * Solution to Grid 1 by Ava Pun
 * Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int H, W;
char arr[1001][1001];
int dp[1001][1001];

int main() {

    cin >> H >> W;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j) 
            cin >> arr[i][j];

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (arr[i][j] == '#') dp[i][j] = 0;
            else if (i == 1 && j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[H][W] << '\n';

}
