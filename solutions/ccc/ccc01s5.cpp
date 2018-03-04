/*
 Solution to CCC '01 S5 - Post's Correspondence Problem by Ava Pun
 Key concepts: brute force
 */
 
#include <bits/stdc++.h>

using namespace std;


int M, N;
string arrA[45], arrB[45];
unordered_set<string> vis;

vector<int> solve(int n, string s, string b, vector<int> v) {
    if (n == 0) {
        if (b == s) {
            return v;
        } else {
            v.clear();
            return v;
        }
    }

    if (b == s && b != "") {
        return v;
    }
    int minN = (int) min(b.length(), s.length());
    if (b.substr(0, minN) != s.substr(0, minN)) {
        v.clear();
        return v;
    }
    for (int i = 1; i <= N; i++) {
        vector<int> v1 = v;
        v1.push_back(i);
        vector<int> ans = solve(n - 1, s + arrA[i], b + arrB[i], v1);
        if (!ans.empty()) {
            return ans;
        }
    }
    v.clear();
    return v;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> arrA[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> arrB[i];
    }

    vector<int> ans;
    ans = solve(M, "", "", ans);
    
    if (ans.empty()) {
        cout << "No solution.";
    } else {
        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << i << "\n";
        }
    }
    
    return 0;
}
