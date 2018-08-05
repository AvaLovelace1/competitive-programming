/*
 Solution to IOI '16 P4 - Paint by Numbers by Ava Pun
 Key concepts: dynamic programming, prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, K;
int C[105], pref[2][MAX], diff[MAX];
bool dp[2][105][MAX], can[2][MAX];

inline int query(int l, int r, int pref[]) {
    return pref[r] - pref[l - 1];
}

string solve_puzzle(string s, int k, int c[]) {
    
    N = (int) s.length(), K = k;
    s = ' ' + s + ' ';
    for (int i = K; i >= 1; i--) {
        C[i] = c[i - 1];
    }
    
    for (int i = 1; i <= N; i++) {
        if (s[i] == '_') {
            pref[0][i] = 1;
        } else if (s[i] == 'X') {
            pref[1][i] = 1;
        }
        pref[0][i] += pref[0][i - 1], pref[1][i] += pref[1][i - 1];
    }
    
    dp[0][0][0] = 1;
    for (int j = 1; j <= N; j++) {
        dp[0][0][j] = !query(1, j, pref[1]);
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (s[j] != 'X') {
                dp[0][i][j] |= dp[0][i][j - 1];
            }
            if (j - C[i] >= 0 && s[j - C[i]] != 'X' && query(j - C[i] + 1, j, pref[0]) == 0) {
                dp[0][i][j] |= dp[0][i - 1][max(0, j - C[i] - 1)];
            }
        }
    }
    dp[1][K + 1][N + 1] = 1;
    for (int j = N; j >= 1; j--) {
        dp[1][K + 1][j] = !query(j, N, pref[1]);
    }
    for (int i = K; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            if (s[j] != 'X') {
                dp[1][i][j] |= dp[1][i][j + 1];
            }
            if (j + C[i] <= N + 1 && s[j + C[i]] != 'X' && query(j, j + C[i] - 1, pref[0]) == 0) {
                dp[1][i][j] |= dp[1][i + 1][min(N + 1, j + C[i] + 1)];
            }
        }
    }

    string ans = s;
    for (int i = 1; i <= K; i++) {
        FILL(diff, 0);
        for (int j = 1; j <= N; j++) {
            if (j + C[i] - 1 <= N && query(j, j + C[i] - 1, pref[0]) == 0 && s[j - 1] != 'X' && s[j + C[i]] != 'X'
                && dp[0][i - 1][max(0, j - 2)] && dp[1][i + 1][min(N + 1, j + C[i] + 1)]) {
                diff[j]++, diff[j + C[i]]--;
            }
            diff[j] += diff[j - 1];
            can[1][j] |= diff[j] != 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (ans[i] == '.') {
            for (int j = 0; j <= K && !can[0][i]; j++) {
                can[0][i] |= dp[0][j][i - 1] && dp[1][j + 1][i + 1];
            }
            if (can[0][i] && can[1][i]) {
                ans[i] = '?';
            } else {
                ans[i] = can[0][i] ? '_' : 'X';
            }
        }
    }

    return ans.substr(1, N);
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }
    cout << solve_puzzle(s, K, C) << '\n';
    
    return 0;
}
