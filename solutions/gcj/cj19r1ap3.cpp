/*
 Solution to Google Code Jam '19 R1A P3 - Alien Rhyme by Ava Pun
 Key concepts: trie
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
const int MAX = 50000 + 5;

int T;
int N, NC = 0;
int trie[MAX][26];
int nWords[MAX];

inline void ins(string str) {
    int n = 0;
    for (char c : str) {
        if (trie[n][c - 'A'] == 0) {
            trie[n][c - 'A'] = ++NC;
        }
        n = trie[n][c - 'A'];
        nWords[n]++;
    }
}

int solve(int n) {
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        if (trie[n][i] != 0) {
            sum += solve(trie[n][i]);
        }
    }
    if (nWords[n] - sum >= 2) {
        sum += 2;
    }   
    return sum;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int test = 1; test <= T; test++) {
        FILL(trie, 0);
        FILL(nWords, 0);
        NC = 0;
        cin >> N;
        string str;
        for (int i = 1; i <= N; i++) {
            cin >> str;
            reverse(str.begin(), str.end());
            ins(str);
        }
        cout << "Case #" << test << ": " << solve(0) << '\n';
    }

    return 0;
}
