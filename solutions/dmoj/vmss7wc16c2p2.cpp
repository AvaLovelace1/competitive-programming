/*
 Solution to VM7WC '16 #2 Silver - GG by Ava Pun
 Key concepts: prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

int Q;
string s;
int pref[100001];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'G') {
            pref[i + 1] = 1;
        }
    }
    
    for (int i = 1; i <= s.length(); i++) {
        pref[i] += pref[i - 1];
    }
    
    cin >> Q;
    int l, r;
    while (Q--) {
        cin >> l >> r;
        cout << pref[r + 1] - pref[l] << "\n";
    }
    
    return 0;
    
}
