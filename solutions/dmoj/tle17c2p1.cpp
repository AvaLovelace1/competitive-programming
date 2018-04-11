/*
 Solution to TLE '17 Contest 2 P1 - Cadadr by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin, s);
    
    int count = 0;
    for (int i = 2; i < s.length() - 4; i++) {
        count++;
        cout << "(c" << s[i] << "r ";
    }
    
    cout << "x";
    
    for (int i = 1; i <= count; i++) {
        cout << ")";
    }
    
    
    return 0;
}
