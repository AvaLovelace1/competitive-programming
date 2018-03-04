/*
 Solution to IOI '98 P1 - Contact by Ava Pun
 Key concepts: complete search, map
 */
 
#include <bits/stdc++.h>

using namespace std;

int A, B, N;
string S;
pair<string, int> m[(1 << 13) + 5];
map< int, vector<int>, greater<int> > ans;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B >> N >> S;
    
    for (int i = 0; i < S.length() - 1; i++) {
        int n = 1;
        string s = "";
        for (int l = 1; l <= B; l++) {
            if (i + l >= S.length()) {
                break;
            }
            n <<= 1;
            if (S[i + l - 1] == '1') {
                n |= 1;
            }
            s += S[i + l - 1];
            if (l >= A) {
                m[n].first = s;
                m[n].second++;
            }
        }
    }
    
    for (int i = 0; i < (1 << (B + 1)); i++) {
        if (m[i].second != 0) {
            ans[m[i].second].push_back(i);
        }
    }
    
    int cnt = 0;
    for (auto i : ans) {
        cout << i.first << " ";
        sort(i.second.begin(), i.second.end(), greater<int>());
        for (int j : i.second) {
            cout << m[j].first;
            cout << " ";
        }
        cnt++;
        if (cnt >= N) {
            break;
        }
        cout << "\n";
    }
    
    return 0;
}
