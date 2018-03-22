/*
 Solution to ECOO '15 R1 P4 - Neanderthal Numbers by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

string s;
string arr[] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
int dp[801];

int solve(int n) {
    
    if (n == -1) {
        return 1;
    }
    
    if (n < 0) {
        return 0;
    }
    
    if (dp[n] == -1) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            bool match = true;
            for (int j = 0; j < arr[i].length() && match; j++) {
                if (n - j < 0 || s[n - j] != arr[i][arr[i].length() - 1 - j]) {
                    match = false;
                }
            }
            if (match) {
                sum += solve(n - (int) arr[i].length());
            }
        }
        dp[n] = sum;
    }
    
    return dp[n];
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i <= 10; i++) {
        cin >> s;
        fill(dp, dp + s.length(), -1);
        cout << solve((int) s.length() - 1) << "\n";
    }
    
    return 0;
    
}
