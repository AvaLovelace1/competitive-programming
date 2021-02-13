/*
 * Solution to Simon Says by Ava Pun
 * Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N;
string S = "Simon says ";

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string str;
    getline(cin, str);
    for (int i = 1; i <= N; ++i) {
        getline(cin, str);
        if (str.length() >= S.length() && str.substr(0, S.length()) == S) {
            cout << str.substr(S.length() - 1) << '\n';
        }
    }

}
