/*
 * Solution to USACO '16 December S2 - Cities and States by Ava Pun
 * Key concepts: implementation, map
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
const int MAX = 2e5 + 2;

int N;
pair<string, string> arr[MAX];
map<string, map<string, int>> mp;

int main() {

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string C, S;
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> C >> S;
        C = C.substr(0, 2);
        ans += S != C ? mp[S][C] : 0;
        arr[i] = {C, S};
        ++mp[C][S];
    }
    cout << ans << '\n';

}
