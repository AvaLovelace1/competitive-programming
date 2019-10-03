/*
 Solution to Plural Form of Nouns by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T, N;
string S;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> S;
        N = S.length();
        if (S.substr(N - 2, 2) == "ch" || S[N - 1] == 'x' || S[N - 1] == 's' || S[N - 1] == 'o') {
            cout << S << "es\n";
        } else if (S.substr(N - 2, 2) == "fe") {
            cout << S.substr(0, N - 2) << "ves\n";
        } else if (S[N - 1] == 'f') {
            cout << S.substr(0, N - 1) << "ves\n";
        } else if (S[N - 1] == 'y') {
            cout << S.substr(0, N - 1) << "ies\n";
        } else {
            cout << S << "s\n";
        }
    }

    return 0;
}
