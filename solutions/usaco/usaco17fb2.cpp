/*
 * Solution to USACO '17 February B2 - Why Did the Cow Cross the Road II by Ava Pun
 * Key concepts: brute force, implementation
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

string S;
int pos[2][26];

int main() {

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    FILL(pos, -1);
    for (int i = 0; i < S.length(); ++i) {
        char c = S[i];
        if (pos[0][c - 'A'] == -1) {
            pos[0][c - 'A'] = i;
        } else {
            pos[1][c - 'A'] = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if ((pos[0][i] < pos[0][j] && pos[0][j] < pos[1][i] && pos[1][i] < pos[1][j]) ||
                (pos[0][j] < pos[0][i] && pos[0][i] < pos[1][j] && pos[1][j] < pos[1][i])) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

}
