/*
 Solution to Word Scrambler by Ava Pun
 Key concepts: recursion, implementation
 */

#include <bits/stdc++.h>

using namespace std;

string str;

void printWays(int pos, string s) {
    if (pos == str.length() - 1) {
        cout << s << "\n";
    } else {
        printWays(pos + 1, s);
        string s1;
        for (int i = pos + 1; i < str.length(); i++) {
            s1 = s.substr(0, pos) + s[i] + s.substr(pos, i - pos) + s.substr(i + 1, s.length() - i - 1);
            printWays(pos + 1, s1);
        }
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    sort(str.begin(), str.end());
    
    printWays(0, str);
    
    return 0;
}
