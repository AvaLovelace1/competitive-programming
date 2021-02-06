/*
 * Solution to USACO '17 January S2 - Hoof, Paper, Scissors by Ava Pun
 * Key concepts: prefix sum array, brute force
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

int N;
int pref[3][MAX];

int quer(int l, int r, int pref[]) {
    return pref[r] - pref[l - 1];
}

int main() {

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    char c;
    for (int i = 1; i <= N; ++i) {
        cin >> c;
        if (c == 'H') {
            pref[0][i] = 1;
        } else if (c == 'P') {
            pref[1][i] = 1;
        } else {
            pref[2][i] = 1;
        }
        for (int j = 0; j < 3; ++j) {
            pref[j][i] += pref[j][i - 1];
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = j + 1; k < 3; ++k) {
                ans = max(ans, quer(1, i, pref[j]) + quer(i + 1, N, pref[k]));
                ans = max(ans, quer(1, i, pref[k]) + quer(i + 1, N, pref[j]));
            }
        }
    }
    cout << ans << '\n';
    
}
