/*
 * Solution to Dunglish by Ava Pun
 * Key concepts: map, counting
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

string C = "correct";
string I = "incorrect";
int N, M;
string arr[22];
unordered_map<string, pii> mp; // corr tot
unordered_map<string, string> dict; // corr tot

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    cin >> M;
    for (int i = 1; i <= M; ++i) {
        string str1, str2, t;
        cin >> str1 >> str2 >> t;
        mp[str1].f += (t[0] == 'c');
        ++mp[str1].s;

        dict[str1] = str2;
    }

    ll corr = 1;
    ll tot = 1;
    for (int i = 1; i <= N; ++i) {
        corr *= mp[arr[i]].f;
        tot *= mp[arr[i]].s;
    }
    ll incorr = tot - corr;

    if ((corr == 1 && incorr == 0) || (corr == 0 && incorr == 1)) {
        for (int i = 1; i <= N; ++i) {
            cout << dict[arr[i]] << " \n"[i == N];
        }
        cout << (corr == 1 ? C : I) << '\n';
    } else {
        cout << corr << '\n';
        cout << C << '\n';
        cout << incorr << '\n';
        cout << I << '\n';
    }

}
