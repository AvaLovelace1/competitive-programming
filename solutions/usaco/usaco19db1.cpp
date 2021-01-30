/*
 * Solution to USACO '19 December B1 - Cow Gymnastics by Ava Pun
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
const int MAX = 52;

int K, N;
int arr[12][22];

int main() {

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            int cow;
            cin >> cow;
            arr[i][cow] = j;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool good = true;
            for (int k = 1; k <= K; ++k) {
                if (arr[k][i] <= arr[k][j]) {
                    good = false;
                    break;
                }
            }
            ans += good;
        }
    }
    cout << ans << '\n';

}
