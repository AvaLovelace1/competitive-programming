/*
 Solution to TLE '16 Contest 8 P1 - Paper Hole Punching by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int N;
    cin >> N;
    
    string s1;
    while (N--) {
        cin >> s1;
        bool ans = true;
        for (char c : s) {
            if (s1.find(c) == string::npos) {
                ans = false;
            }
        }
        cout << (ans ? "yes\n" : "no\n");
    }
    
    return 0;
}
