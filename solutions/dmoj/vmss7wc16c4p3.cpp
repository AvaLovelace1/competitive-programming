/*
 Solution to VM7WC '16 #4 Gold - Restoring Reputation by Ava Pun
 Key concepts: dynamic programming, edit distance
 */

#include <bits/stdc++.h>

using namespace std;

int D, I, R;
string A, B;
int dp[1001][1001];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> D >> I >> R >> A >> B;
    
    for (int i = 0; i <= A.length(); i++) {
        for (int j = 0; j <= B.length(); j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = j * I;
            } else if (j == 0) {
                dp[i][j] = i * D;
            } else {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j] + D, dp[i][j - 1] + I), dp[i - 1][j - 1] + R);
                }
            }
        }
    }
    
    cout << dp[A.length()][B.length()];
    
    return 0;
}
