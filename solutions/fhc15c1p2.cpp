/*
 Solution to Autocomplete by Ava Pun
 Key concepts: trie
 */

#include <bits/stdc++.h>

using namespace std;

int T, N, cnt;
string S;
int trie[1000001][27];

void insert(string s) {
    int n = 0;
    for (char c : s) {
        if (trie[n][c - 'a'] == 0) {
            trie[n][c - 'a'] = cnt;
            cnt++;
        }
        n = trie[n][c - 'a'];
        trie[n][26]++;
    }
}

int query(string s) {
    int n = 0, i = 0;
    while (i < s.length()) {
        char c = s[i];
        n = trie[n][c - 'a'];
        if (trie[n][26] == 1) {
            break;
        }
        i++;
    }
    if (i == s.length()) {
        i--;
    }
    return i + 1;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        cin >> N;
        cnt = 1;
        memset(trie, 0, sizeof(trie));
        int ans = 0;
        while (N--) {
            cin >> S;
            insert(S);
            ans += query(S);
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
    
    return 0;
}
