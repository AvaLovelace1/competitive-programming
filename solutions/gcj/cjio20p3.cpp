/*
 Solution to Google Code Jam to I/O for Women '20 P3 - Interleaved Output: Part 2 by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T, N;
string S;
int dp[105][20];

inline int convert(int IO, int Io, int iO, int io) {
    return IO * 8 + Io * 4 + iO * 2 + io;
}

int solve(int n, int IO, int Io, int iO, int io) {
    int k = convert(IO, Io, iO, io);
    if (dp[n][k] == -1) {
        if (n == 0) {
            if (k == 0) {
                dp[n][k] = 0;
            } else {
                dp[n][k] = -INF;
            }
        } else {
            dp[n][k] = -INF;
            if (S[n] == 'I') {
                if (Io > 0) dp[n][k] = max(dp[n][k], solve(n - 1, IO, Io - 1, iO, io));
                if (IO > 0) dp[n][k] = max(dp[n][k], solve(n - 1, IO - 1, Io, iO, io));
            } else if (S[n] == 'i') {
                if (iO > 0) dp[n][k] = max(dp[n][k], solve(n - 1, IO, Io, iO - 1, io));
                if (io > 0) dp[n][k] = max(dp[n][k], solve(n - 1, IO, Io, iO, io - 1));
            } else if (S[n] == 'O') {
                if (IO < 1) dp[n][k] = max(dp[n][k], solve(n - 1, IO + 1, Io, iO, io) + 1);
                if (iO < 1) dp[n][k] = max(dp[n][k], solve(n - 1, IO, Io, iO + 1, io));
            } else if (S[n] == 'o') {
                if (Io < 1) dp[n][k] = max(dp[n][k], solve(n - 1, IO, Io + 1, iO, io));
                if (io < 1) dp[n][k] = max(dp[n][k], solve(n - 1, IO, Io, iO, io + 1));
            }
        }

    }
    return dp[n][k];
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        FILL(dp, -1);
        cin >> S;
        N = (int) S.length();
        S = '0' + S;
        cout << "Case #" << t << ": " << solve(N, 0, 0, 0, 0) << '\n';
    }

    return 0;
}
