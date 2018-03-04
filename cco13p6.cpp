/*
 Solution to CCO '13 P6 - Repetitivity by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

int MOD;
string s;
int dp[10001][10001];

int findWays(int a, int b) {
    
    if (a < 0 || b < 0) {
        return 0;
    }
    
    if (dp[a][b] == -1) {
        int sum;
        if (s[a] == s[b]) {
            sum = (1 + (findWays(a - 1, b) + findWays(a, b - 1)) % MOD) % MOD;
        } else {
            sum = ((findWays(a - 1, b) + findWays(a, b - 1)) % MOD - findWays(a - 1, b - 1) + MOD) % MOD;
        }
        dp[a][b] = sum;
    }
    
    return dp[a][b];
    
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> MOD;
    
    memset(dp, -1, sizeof dp);
    
    cout << (findWays(s.length() - 1, s.length() - 1) + 1) % MOD;
    
    return 0;
}
