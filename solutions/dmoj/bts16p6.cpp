/*
 Solution to Back to School '16: Times Table by Ava Pun
 Key concepts: 2D prefix sum array, dynamic programming
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

const pii dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int C, R, M;
ll arr[505][505];
int SC, SR;
pair<int, ll> dp[505][505];

inline void updUtil(int r1, int c1, int r2, int c2, int x) {
    arr[r1][c1] += x, arr[r1][c2 + 1] -= x, arr[r2 + 1][c1] -= x, arr[r2 + 1][c2 + 1] += x; 
}

inline void upd(int r, int c, int h, int w, int x) {
    updUtil(r, c, r + h - 1, c + w - 1, x);
    updUtil(r + h, c, r + h, c + w - 1, -h * x);
    updUtil(r, c + w, r + h - 1, c + w, -w * x);
    updUtil(r + h, c + w, r + h, c + w, h * w * x);
}

pair<int, ll> solve(int r, int c) {
    pair<int, ll> &ret = dp[r][c];
    if (ret.f == 0) {
        ret = {1, arr[r][c]};
        for (auto p : dirs) {
            int r1 = r + p.f, c1 = c + p.s;
            if (arr[r1][c1] > arr[r][c]) {
                pair<int, ll> nxt = solve(r1, c1);
                ret = max(ret, {nxt.f + 1, nxt.s + arr[r][c]});
            }
        }
    }
    return ret;
}

int main() {

    scanf("%d%d%d", &C, &R, &M);
    int c, r, w, h, n;
    while (M--) {
        scanf("%d%d%d%d%d", &c, &r, &w, &h, &n);
        upd(r, c, h, w, n);
    }
    for (int t = 1; t <= 2; t++) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                arr[i][j] += arr[i][j - 1];
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                arr[i][j] += arr[i - 1][j];
            }
        }
    }
    scanf("%d%d", &SC, &SR);
    printf("%lld\n", solve(SR, SC).s % MOD);

    return 0;
}
