/*
 Solution to ECOO '16 R2 P2 - CC+ by Ava Pun
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
const int MAX = 675 * 25 + 5;

int N, K;
string S;
int words[680];
int wordCnt = 1;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int test = 1; test <= 10; test++) {

        FILL(words, 0);
        wordCnt = 1;
        cin >> K;
        K %= 26;
        cin.ignore();
        getline(cin, S);
        
        bool encode = false;
        for (char c : S) {
            if (c == ' ') {
                encode = true;
            }
        }
        
        if (encode) {
            
            for (int i = 0; i < S.length(); i++) {
                if (S[i] == ' ') {
                    S = S.substr(0, i) + S.substr(i + 1, string::npos);
                    i--;
                    wordCnt++;
                } else {
                    words[wordCnt]++;
                }
            }
            
            string ans = "";
            ans += wordCnt / 26 + 'a';
            ans += wordCnt % 26 + 'a';
            for (int i = 1; i <= wordCnt; i++) {
                ans += (char) (words[i] + 'a');
            }
            S = ans + S;
            N = (int) S.length();
            
            int sum = 0;
            for (int i = N - 1; i >= 0; i--) {
                int c = S[i] - 'a';
                S[i] = ((S[i] - 'a') + sum + K) % 26 + 'a';
                sum = (sum + c) % 26;
            }
            cout << S << "\n";
            
        } else {
            
            N = (int) S.length();
            int sum = 0;
            for (int i = N - 1; i >= 0; i--) {
                S[i] = (((S[i] - 'a') - sum - K) % 26 + 26) % 26 + 'a';
                int c = S[i] - 'a';
                sum = (sum + c) % 26;
            }

            wordCnt = (S[0] - 'a') * 26 + (S[1] - 'a');
            for (int i = 2; i < 2 + wordCnt; i++) {
                words[i - 1] = S[i] - 'a';
            }
            
            int cnt = 1;
            for (int i = 2 + wordCnt; i < N; i++) {
                cout << S[i];
                words[cnt]--;
                if (!words[cnt]) {
                    cout << ' ';
                    cnt++;
                }
            }
            cout << "\n";
        }
        
    }
    
    return 0;
}
