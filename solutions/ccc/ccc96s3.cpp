/*
 Solution to CCC '96 S3 - Pattern Generator by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N;

void printPatterns(int n, int k, string s) {
    if (n > s.length()) {
        return;
    }
    if (k == 0) {
        cout << s << "\n";
    } else {
        string s2 = s;
        s2[n] = '1';
        printPatterns(n + 1, k - 1, s2);
        printPatterns(n + 1, k, s);
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int n, k;
    string s;
    
    while (N--) {
        cin >> n >> k;
        s = "";
        for (int i = 1; i <= n; i++) {
            s += '0';
        }
        cout << "The bit patterns are\n";
        printPatterns(0, k, s);
        cout << "\n";
    }
    
    return 0;
    
}
