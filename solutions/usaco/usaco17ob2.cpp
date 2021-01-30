/*
 * Solution to USACO '17 Open B2 - Bovine Genomics by Ava Pun
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

int N, M;
string arr[2][102];

int main() {

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        unordered_set<char> ss{};
        for (int j = 1; j <= N; ++j) {
            ss.insert(arr[0][j][i]);
        }
        bool good = true;
        for (int j = 1; j <= N; ++j) {
            if (ss.find(arr[1][j][i]) != ss.end()) {
                good = false;
                break;
            }
        }
        ans += good;
    }
    cout << ans << '\n';

}
