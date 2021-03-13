/*
 * Solution to Dreamoon and Strings by Ava Pun
 * Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 5;

string S, P;
int N, M, K;
vi dp[2005][505];
int minX[2005];

int solve(int n, int m, int occ) {
    if (occ < 0) return INF;
    int &ans = dp[n][m][occ];
    if (ans != -1) return ans;
    else if (n == N + 1) {
        if (occ == 0) ans = 0;
        else ans = INF;
        return ans;
    } else {
        if (m == 0) {
            ans = solve(n + 1, m, occ);
            ans = min(ans, solve(n, 1, occ));
        } else if (m == M) {
            ans = solve(n + 1, m, occ) + 1;
            if (S[n] == P[m]) {
                ans = min(ans, solve(n + 1, 0, occ - 1));
            }
        } else {
            ans = solve(n + 1, m, occ) + 1;
            if (S[n] == P[m]) {
                ans = min(ans, solve(n + 1, m + 1, occ));
            }
        }
        return ans;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> S >> P;
    N = (int) S.length();
    M = (int) P.length();
    K = N / M;
    S = ' ' + S;
    P = ' ' + P;

    REP(i, 0, N + 1) {
        REP(j, 0, M + 1) {
            dp[i][j] = vi(K + 2, -1);
        }
    }

    REP(k, 0, K) {
        minX[k] = solve(1, 0, k);
    }

    int k = 0;
    REP(n, 0, N) {
        while (k + 1 <= K && minX[k + 1] <= n) ++k;
        int used = k * M;
        int erased = minX[k];
        int erasedLeft = n - erased;
        int leftover = N - erased - used;
        int overflowChars = max(0, erasedLeft - leftover);
        int overflowOccs = (overflowChars + M - 1) / M;
        int ans = k - overflowOccs;
        cout << ans << " \n"[n == N];
    }
    
}

