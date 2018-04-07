/*
 Solution to TLE '17 Contest 1 P1 - String Rounding by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

string round(string s, long pos) {
    
    if (s[pos] >= 'n' && s[pos] <= 'z') {
        s[pos] = 'a';
        if (pos >= 1) {
            if (s[pos - 1] != 'z') {
                s[pos - 1]++;
            } else {
                s = round(s, pos - 1);
            }
        } else {
            s = 'a' + s;
        }
    } else {
        s[pos] = 'a';
    }
    return s;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    
    cin >> s;
    string str = round(s, s.length() - 1);
    
    cout << str;
    
    return 0;
    
}
