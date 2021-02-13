/*
 * Solution to Forest Queries by Ava Pun
 * Key concepts: 2D prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N, Q;
int pref[1002][1002];

int quer(int y1, int x1, int y2, int x2) {
    return pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    char c;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> c;
            pref[i][j] = (c == '*');
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    int y1, x1, y2, x2;
    for (int i = 1; i <= Q; ++i) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << quer(y1, x1, y2, x2) << '\n';
    }

}
