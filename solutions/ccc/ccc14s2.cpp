/*
 Solution to CCC '14 S2 - Assigning Partners by Ava Pun
 Key concepts: implementation
 */
 
 #include <bits/stdc++.h>

using namespace std;

int N;
map<string, string> m;
string arr[31];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        arr[i] = s;
    }
    bool good = true;
    for (int i = 0; i < N && good; i++) {
        cin >> s;
        if (m.find(arr[i]) == m.end()) {
            if (arr[i] == s) {
                good = false;
            } else {
                m[arr[i]] = s;
                m[s] = arr[i];
            }
        } else if (m[arr[i]] != s) {
            good = false;
        }
    }
    
    cout << (good ? "good" : "bad");
    
    return 0;
    
}
