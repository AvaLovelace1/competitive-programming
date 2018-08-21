/*
 Solution to Single Wildcard Pattern Matching by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M;
string S, T;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> S >> T;
    
    int pos = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] == '*') {
            pos = i;
            break;
        }
    }
    
    bool good = 0;
    if (pos == -1) {
        good = S == T;
    } else {
        good = S.substr(0, pos) == T.substr(0, min(M, pos));
        int len = N - pos - 1;
        good &= S.substr(pos + 1, len) == T.substr(max(0, M - len), min(M, len)) && pos - 1 < M - len;
    }
    
    printf(good ? "YES\n" : "NO\n");
    
    return 0;
}
