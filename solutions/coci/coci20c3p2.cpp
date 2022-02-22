/*
 * Solution to COCI '20 Contest 3 #2 Vlak by Ava Pun
 * Key concepts: trie, dynamic programming on trees
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 2e5 + 5;

int N[2];
int trie[MAX][26];
bool fav[2][MAX];
int cnt = 1;

void add(const string &str, int t) {
    int u = 0;
    for (char c : str) {
        if (trie[u][c-'a'] == 0) trie[u][c-'a'] = cnt++;
        u = trie[u][c-'a'];
        fav[t][u] = 1;
    }
}

int solve(int u, bool t) {
    REP(i, 0, 25) {
        if (trie[u][i] && fav[t][trie[u][i]]) {
            if (!solve(trie[u][i], !t)) return 1;
        }
    }
    return 0;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    REP(t, 0, 1) {
        cin >> N[t];
        REP(i, 1, N[t]) {
            string str;
            cin >> str;
            add(str, t);
        }
    }

    cout << (solve(0, 0) ? "Nina" : "Emilija") << '\n';

}
