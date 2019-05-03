/*
 Solution to DMPG '19 B4 - Braille by Ava Pun
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

const string engToBr[] = {"......", "o.....", "o.o...", "oo....", "oo.o..", "o..o..", "ooo...", "oooo..", "o.oo..", ".oo...", ".ooo..",
    "o...o.", "o.o.o.", "oo..o.", "oo.oo.", "o..oo.", "ooo.o.", "ooooo.", "o.ooo.", ".oo.o.", ".oooo.",
    "o...oo", "o.o.oo", ".ooo.o", "oo..oo", "oo.ooo", "o..ooo"};
string S;

int main() {
    
    getline(cin, S);
    assert(S.length() <= 1000);
    string l1 = "", l2 = "", l3 = "";
    for (char c : S) {
        assert(c == ' ' || (c >= 'A' && c <= 'Z'));
        int idx = c == ' ' ? 0 : c - 'A' + 1;
        l1 += engToBr[idx].substr(0, 2);
        l2 += engToBr[idx].substr(2, 2);
        l3 += engToBr[idx].substr(4, 2);
    }
    cout << l1 << '\n' << l2 << '\n' << l3 << '\n';

    return 0;
}
