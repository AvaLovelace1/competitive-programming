/*
 Solution to Autocomplete Strikes Back by Ava Pun
 Key concepts: dynamic programming on trie
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<bool, int> pii;
const int INF = 0x3F3F3F3F;

int T, N, K, cnt;
string str;
int trie[20001][26];
pii trieVals[20001];
bool vis[20001];
int dp[20001][101];

void insert(string s, int num) {
    int n = 0;
    for (char c : s) {
        if (trie[n][c - 'a'] == 0) {
            cnt++;
            trie[n][c - 'a'] = cnt;
        }
        trieVals[trie[n][c - 'a']].second = trieVals[n].second + 1;
        n = trie[n][c - 'a'];
    }
    trieVals[n].first = true;
}

void solve(int n) {
    if (!vis[n]) {
        vis[n] = true;
        dp[n][0] = 0;
        if (trieVals[n].first) {
            dp[n][1] = trieVals[n].second;
        }
        for (int i = 0; i < 26; i++) {
            if (trie[n][i] != 0) {
                if (!vis[trie[n][i]]) {
                    solve(trie[n][i]);
                }
                for (int j = K; j >= 0; j--) {
                    for (int k = 0; k <= j; k++) {
                        dp[n][j] = min(dp[n][j], dp[n][j - k] + dp[trie[n][i]][k]);
                    }
                    //cout << n << " " << j << " " << dp[n][j] << "\n";
                }
            }
        }
        dp[n][1] = trieVals[n].second;
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        
        cnt = 0;
        memset(trie, 0, sizeof(trie));
        memset(trieVals, 0, sizeof(trieVals));
        memset(dp, INF, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> str;
            insert(str, i);
        }
        
        solve(0);
        
        cout << "Case #" << t << ": " << dp[0][K] << "\n";
        
    }
    
    return 0;
}
