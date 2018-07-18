/*
 Solution to TLE '17 Contest 2 P6 - Save Jody! by Ava Pun
 Key concepts: dynamic programming, matrix exponentiation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int N, H, L, S, LOG;
set<pii> pillars;
set<int> pillarsX;
int cnt = 0;
ll dp[2][205], mat[32][205][205], tmp[205];
vi nxt[205];

inline void mult(ll a[][205], ll b[][205], ll c[][205]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            c[i][j] = 0;
            for (int k = 0; k < H; k++) {
                c[i][j] += a[i][k] * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
}

inline void mult(ll a[][205], ll b[], ll c[]) {
    for (int i = 0; i < H; i++) {
        c[i] = 0;
        for (int k = 0; k < H; k++) {
            c[i] += a[i][k] * b[k] % MOD;
            c[i] %= MOD;
        }
    }
}

inline void copyMat(ll a[], ll b[]) {
    for (int i = 0; i < H; i++) {
        b[i] = a[i];
    }
}

inline void comp(int n, ll a[], ll b[]) {
    int d = LOG;
    while (n) {
        if ((1 << d) <= n) {
            mult(mat[d], a, tmp);
            copyMat(tmp, a);
            n -= 1 << d;
        }
        d--;
    }
    copyMat(a, b);
}

int main() {
    
    scanf("%d%d%d%d", &N, &H, &L, &S);
    LOG = ceil(log2(L));
    int x, y;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &x, &y);
        pillars.insert({x, y});
        pillarsX.insert(x - 1);
    }
    
    for (int i = 0; i < H; i++) {
        if (i != 0) {
            mat[0][i][i - 1] = 1;
        }
        mat[0][i][i] = 1;
        if (i != H - 1) {
            mat[0][i][i + 1] = 1;
        }
    }
    for (int i = 1; i <= LOG; i++) {
        mult(mat[i - 1], mat[i - 1], mat[i]);
    }
    
    dp[0][S] = 1;
    int prev = 0;
    for (int i : pillarsX) {
        
        comp(i - prev, dp[0], dp[1]);
        for (int j = 0; j < H; j++) {
            dp[0][j] = 0;
            nxt[j].clear();
        }
        
        int curr = -1, blocked = -1;
        for (int j = 0; j < H; j++) {
            if (curr != -1 && curr >= blocked && (pillars.count({i + 1, j}) || (!pillars.count({i + 1, j}) && curr == j - 1))) {
                nxt[j].pb(curr);
            }
            if (!pillars.count({i + 1, j})) {
                nxt[j].pb(j);
                curr = j;
            }
            if (pillars.count({i, j})) {
                blocked = j;
            }
        }
        curr = -1, blocked = H;
        for (int j = H - 1; j >= 0; j--) {
            if (curr != -1 && curr <= blocked && (pillars.count({i + 1, j}) || (!pillars.count({i + 1, j}) && curr == j + 1))) {
                nxt[j].pb(curr);
            }
            if (!pillars.count({i + 1, j})) {
                curr = j;
            }
            if (pillars.count({i, j})) {
                blocked = j;
            }
        }
        
        for (int j = 0; j < H; j++) {
            for (int j1 : nxt[j]) {
                dp[0][j1] += dp[1][j];
                dp[0][j1] %= MOD;
            }
        }
        prev = i + 1;
    }
    comp(L - prev, dp[0], dp[1]);

    int ans = 0;
    for (int j = 0; j < H; j++) {
        ans += dp[1][j];
        ans %= MOD;
    }
    printf("%d\n", ans);
    
    return 0;
}
