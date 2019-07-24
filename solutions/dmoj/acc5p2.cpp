/*
 Solution to Another Contest 5 Problem 2 - Great Graffiti by Ava Pun
 Key concepts: brute force
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
string S;

string ins(string str, int pos, char c) {
    return str.substr(0, pos) + c + str.substr(pos, string::npos);
}

int solve(string str, int n) {
    if (str.find("DMOJ") != string::npos) {
        return n;
    }
    if (n >= 4) {
        return INF;
    }
    int ans = 4;
    for (int i = 0; i <= str.length(); i++) {
        ans = min(ans, solve(ins(str, i, 'D'), n + 1));
        ans = min(ans, solve(ins(str, i, 'M'), n + 1));
        ans = min(ans, solve(ins(str, i, 'O'), n + 1));
        ans = min(ans, solve(ins(str, i, 'J'), n + 1));
    }
    return ans;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    cout << solve(S, 0) << '\n';
    
    return 0;
}
