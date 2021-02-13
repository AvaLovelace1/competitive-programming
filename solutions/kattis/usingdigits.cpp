/*
 * Solution to Using Digits by Ava Pun
 * Key concepts: dynamic programming on grid
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

int X, Y, K;
string S;
int code[105];
int arr[105][105];
int dp[105][105][55];

int solve(int y, int x, int k) {
    if (y > Y || x > X) return INF;
    int &ans = dp[y][x][k];
    if (ans != -1) return ans;
    else if (y == Y && x == X) return ans = arr[y][x];
    else {
        int mn = INF;
        mn = min(mn, solve(y + 1, x, k));
        mn = min(mn, solve(y, x + 1, k));
        if (k <= K) {
            mn = min(mn, solve(y + code[k] + 1, x, k + 1));
            mn = min(mn, solve(y, x + code[k] + 1, k + 1));
        }
        ans = mn + arr[y][x];
        return ans;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y >> S;
    K = S.length();
    for (int i = 0; i < K; ++i) {
        code[i + 1] = S[i] - '0';
    }
    for (int i = Y; i >= 1; --i) {
        for (int j = 1; j <= X; ++j) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    FILL(dp, -1);
    cout << solve(1, 1, 1) << '\n';
    /*
    for (int i = Y; i >= 1; --i) {
        for (int j = 1; j <= X; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/

}
