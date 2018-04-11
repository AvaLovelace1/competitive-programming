/*
 Solution to String Finding (Hard) by Ava Pun
 Key concepts: KMP
 */

#include <bits/stdc++.h>

using namespace std;

string S, T;
int lps[1000001] = {};

int kmp() {
    int i = 0, j = 0;
    while (i < S.length()) {
        if (S[i] == T[j]) {
            i++;
            j++;
            if (j == T.length()) {
                return i - j;
            }
        } else if (j != 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return -1;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S >> T;
    
    int len = 0;
    int i = 1;
    while (i < T.length()) {
        if (T[i] == T[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    cout << kmp();
    
    return 0;
}
