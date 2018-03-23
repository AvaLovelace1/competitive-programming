/*
 Solution to Mock CCC '18 Contest 1 J4/S2 - A Square Problem by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N;
string arr[40];

bool distinctCol(int n) {
    unordered_set<char> s;
    for (int i = 0; i < N; i++) {
        if (s.find(arr[i][n]) == s.end()) {
            s.insert(arr[i][n]);
        } else {
            return false;
        }
    }
    return true;
}

bool distinctRow(int n) {
    unordered_set<char> s;
    for (int i = 0; i < N; i++) {
        if (s.find(arr[n][i]) == s.end()) {
            s.insert(arr[n][i]);
        } else {
            return false;
        }
    }
    return true;
}

bool latin() {
    for (int i = 0; i < N; i++) {
        if (!distinctCol(i) || !distinctRow(i)) {
            return false;
        }
    }
    return true;
}

bool reduced() {
    for (int i = 0; i < N - 1; i++) {
        if (arr[0][i + 1] < arr[0][i] || arr[i + 1][0] < arr[i][0]) {
            return false;
        }
    }
    return true;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    if (latin()) {
        if (reduced()) {
            cout << "Reduced\n";
        } else {
            cout << "Latin\n";
        }
    } else {
        cout << "No\n";
    }
    
    return 0;
}
