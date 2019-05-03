/*
 Solution to DMPG '19 S2 - Code Cracking Crisis by Ava Pun
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

string keys[10];
string S;

int main() {
    
    string str;
    for (int i = 0; i < 10; i++) {
        cin >> str;
        keys[i] = "          ";
        for (int j = 0; j < 10; j++) {
            keys[i][str[j] - '0'] = j + '0';
        }
    }
    cin >> S;

    string ans = "";
    ans += S[0];
    for (int i = 1; i < S.length(); i++) {
        ans += keys[ans[i - 1] - '0'][S[i] - '0'];
    }
    cout << ans << '\n';

    return 0;
}
