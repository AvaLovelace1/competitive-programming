/*
 Solution to APIO '11 P1 - Color by Ava Pun
 Key concepts: disjoint set, 2SAT, combinatorics
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9;
const int MAX = 1e5 + 5;

int N[2], K;
vii events[2][MAX];
int par[2][2 * MAX], rnk[2][2 * MAX];
int NC[2];

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ret = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ret = ret * a % MOD;
        }   
        return ret;
    }
}

int Find(int x, bool idx) {
    if (par[idx][x] != x) {
        par[idx][x] = Find(par[idx][x], idx);
    }
    return par[idx][x];
}

inline bool Union(int a, int b, int idx) {
    a = Find(a, idx), b = Find(b, idx);
    if (a == b) {
        return 0;
    }
    if (rnk[idx][a] < rnk[idx][b]) {
        swap(a, b);
    }
    par[idx][b] = a;
    if (rnk[idx][a] == rnk[idx][b]) {
        rnk[idx][a]++;
    }
    NC[idx]--;
    return 1;
}

inline bool Union(int a, int b, int xo, int idx) {
    if (xo) {
        return Union(a, b + N[idx], idx) && Union(a + N[idx], b, idx);
    } else {
        return Union(a, b, idx) && Union(a + N[idx], b + N[idx], idx);
    }
}

int main() {

    scanf("%d%d%d", &N[0], &N[1], &K);
    int r, c, bw;
    for (int i = 1; i <= K; i++) {
        scanf("%d%d%d", &r, &c, &bw);
        if ((r & 1) && (c & 1)) {
            bw ^= 1;
        }
        events[0][r].pb({c, bw});
        events[1][c].pb({r, bw});
    }
    for (int idx = 0; idx <= 1; idx++) {
        NC[idx] = 2 * N[idx];
        for (int i = 1; i <= 2 * N[idx]; i++) {
            par[idx][i] = i;
        }
    }

    for (int idx = 0; idx <= 1; idx++) {
        for (int i = 1; i <= N[idx]; i++) {
            for (int j = 1; j < events[idx][i].size(); j++) {
                int c1 = events[idx][i][j - 1].f, c2 = events[idx][i][j].f;
                int xo = events[idx][i][j - 1].s ^ events[idx][i][j].s;
                Union(c1, c2, xo, !idx);
            }
        }
    }
    for (int idx = 0; idx <= 1; idx++) {
        for (int i = 1; i <= N[idx]; i++) {
            if (Find(i, idx) == Find(i + N[idx], idx)) {
                printf("0\n");
                exit(0);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N[0]; i++) {
        if (events[0][i].empty()) {
            cnt++;
        }
    }
    printf("%lld\n", modPow(2, cnt + NC[1] / 2 - 1));

    return 0;
}
