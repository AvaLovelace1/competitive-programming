/*
 Solution to Mock CCC '18 Contest 3 J3/S1 - A String Problem by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

string s;
unordered_map<char, int> m;
vector<int> arr;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    
    for (char c : s) {
        m[c]++;
    }
    for (auto p : m) {
        arr.push_back(p.second);
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    if (arr.size() <= 2) {
        cout << 0 << "\n";
    } else {
        cout << (s.length() - arr[0] - arr[1]) << "\n";
    }
    
    return 0;
}
