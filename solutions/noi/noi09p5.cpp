/*
 Solution to NOI '09 P5 - Pipe Marbles by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1024523;

int N, M;
int same = 0;
string pipe1, pipe2;
unordered_map< int, unordered_map<int, int> > dp[501][501];

bool compare(int a, int b) {
    if (a > same || b > same || a != b ) {
        return false;
    } else {
        return true;
    }
}

int findWays(int a1, int a2, int b1, int b2) {
    
    if (dp[a1][a2][b1].find(b2) == dp[a1][a2][b1].end()) {
        if (a1 == 0 && b2 == 0) {
            if (compare(a2, b1)) {
                dp[a1][a2][b1][b2] = 1;
            } else {
                dp[a1][a2][b1][b2] = 0;
            }
        } else if (a2 == 0 && b1 == 0) {
            if (compare(a1, b2)) {
                dp[a1][a2][b1][b2] = 1;
            } else {
                dp[a1][a2][b1][b2] = 0;
            }
        } else if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
            dp[a1][a2][b1][b2] = 1;
        } else {
            int sum = 0;
            if (pipe1[a1 - 1] == pipe1[b1 - 1]) {
                sum += findWays(a1 - 1, a2, b1 - 1, b2);
                sum %= MOD;
            }
            if (pipe1[a1 - 1] == pipe2[b2 - 1]) {
                sum += findWays(a1 - 1, a2, b1, b2 - 1);
                sum %= MOD;
            }
            if (pipe2[a2 - 1] == pipe1[b1 - 1]) {
                sum += findWays(a1, a2 - 1, b1 - 1, b2);
                sum %= MOD;
            }
            if (pipe2[a2 - 1] == pipe2[b2 - 1]) {
                sum += findWays(a1, a2 - 1, b1, b2 - 1);
                sum %= MOD;
            }
            dp[a1][a2][b1][b2] = sum;
        }
    }
    
    return dp[a1][a2][b1][b2];
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> pipe1 >> pipe2;
    
    for (int i = 0; i < M && i < N; i++) {
        if (pipe1[i] != pipe2[i]) {
            break;
        }
        same++;
    }
    
    cout << findWays(N, M, N, M);
    
    return 0;
    
}
