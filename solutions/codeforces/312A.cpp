/*
 * Solution to Whose sentence is it? by Ava Pun
 * Key concepts: implementation
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
const int MAX = 1e5 + 5;

int N;
string S;
const string LALA = "lala.";
const string MIAO = "miao.";

bool isF(string &S) {
    return S.length() >= LALA.length() && S.substr(S.length() - LALA.length(), string::npos) == LALA;
}
bool isR(string &S) {
    return S.length() >= MIAO.length() && S.substr(0, MIAO.length()) == MIAO;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    getline(cin, S);
    REP(i, 1, N) {
        getline(cin, S);
        bool f = isF(S);
        bool r = isR(S);
        if (f ^ r) {
            cout << (f ? "Freda's\n" : "Rainbow's\n");
        } else cout << "OMG>.< I don't know!\n";
    }

}

