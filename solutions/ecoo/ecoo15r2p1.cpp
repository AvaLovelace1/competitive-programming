/*
 Solution to ECOO '15 R2 P1 - The Interlace Cypher by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

vii words;
vector<string> ansWords;
string T, S, ans;
int cnt = 0;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int test = 1; test <= 10; test++) {
        
        words.clear();
        words.resize(1);
        ansWords.clear();
        ans = "";
        cnt = 0;
        cin >> T;
        cin.ignore();
        getline(cin, S);
        
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == ' ') {
                cnt++;
                words.resize(cnt + 1);
                words[cnt].f = i + 1;
            } else {
                words[cnt].s++;
            }
        }
        
        if (T == "encode") {
            
            bool done = false;
            while (!done) {
                done = true;
                for (int i = 0; i <= cnt; i++) {
                    if (words[i].s) {
                        ans += S[words[i].f];
                        words[i].f++;
                        words[i].s--;
                        done = false;
                    }
                }
            }
            
            for (int i = 0; i < cnt; i++) {
                ans = ans.substr(0, words[i].f) + ' ' + ans.substr(words[i].f, string::npos);
            }
            cout << ans << "\n";
            
        } else {
            
            ansWords.resize(cnt + 1);
            int curr = 0;
            for (char c : S) {
                if (c != ' ') {
                    while (ansWords[curr].length() >= words[curr].s) {
                        curr++;
                        if (curr > cnt) {
                            curr = 0;
                        }
                    }
                    ansWords[curr] += c;
                    curr++;
                    if (curr > cnt) {
                        curr = 0;
                    }
                }
            }
            for (int i = 0; i < ansWords.size(); i++) {
                cout << ansWords[i];
                if (i != ansWords.size() - 1) {
                    cout << ' ';
                }
            }
            cout << "\n";
            
        }
        
    }
    
    return 0;
}
