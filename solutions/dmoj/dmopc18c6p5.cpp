/*
 Solution to DMOPC '18 Contest 6 P5 - Quadrat Sampling by Ava Pun
 Key concepts: line sweep, segment tree with lazy propagation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, K, Q, T, N1, M1, H;
int geese[2][MAX];
pii quads[2][MAX], quers[2][MAX];
int ans[MAX];
vi cpr[2];
vector<piii> events[3][3 * MAX];
int tree[6 * MAX], lazy[3 * MAX];

inline void apply(int pos, int x) {
    tree[pos] += x;
    if (pos < M1) {
        lazy[pos] += x;
    }
}

inline void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]) + lazy[i];
    }
}

inline void down(int pos) {
    for (int sh = H; sh > 0; sh--) {
        int i = pos >> sh;
        if (lazy[i] != 0) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

inline void upd(int l, int r, int x) {
    r--;
    l += M1 - 1, r += M1 - 1;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l & 1) {
            apply(l, x);
            l++;
        }
        if (!(r & 1)) {
            apply(r, x);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    up(l0), up(r0);
}

inline int quer(int l, int r) {
    l = max(1, l), r = min(M1, r);
    l += M1 - 1, r += M1 - 1;
    down(l), down(r);
    int ret = 0;
    while (l <= r) {
        if (l & 1) {
            ret = max(ret, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            ret = max(ret, tree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ret;
}

inline int getIdx(int x, int t) {
    return (int) (lower_bound(cpr[t].begin(), cpr[t].end(), x) - cpr[t].begin());
}
inline int getIdxUpper(int x, int t) {
    return (int) (upper_bound(cpr[t].begin(), cpr[t].end(), x) - cpr[t].begin());
}

inline void solve(int a, int b) {
    
    N1 = (int) cpr[a].size() - 1;
    M1 = (int) cpr[b].size() - 1;
    H = 8 * sizeof(int) - __builtin_clz(M1);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N1; j++) {
            events[i][j].clear();
        }
    }
    FILL(tree, 0), FILL(lazy, 0);
    
    for (int i = 1; i <= K; i++) {
        events[2][geese[a][i]].pb({i, quers[b][i]});
    }
    for (int i = 1; i <= Q; i++) {
        events[1][quads[a][i].f].pb({0, quads[b][i]});
        events[0][quads[a][i].s].pb({0, quads[b][i]});
    }
    
    for (int i = 1; i <= N1; i++) {
        for (auto p : events[0][i]) {
            upd(p.s.f, p.s.s, -1);
        }
        for (auto p : events[1][i]) {
            upd(p.s.f, p.s.s, 1);
        }
        for (auto p : events[2][i]) {
            ans[p.f] = max(ans[p.f], quer(p.s.f, p.s.s));
        }
    }
}

int main() {
    
    scanf("%d%d%d%d%d", &N, &M, &K, &Q, &T);
    for (int i = 1; i <= K; i++) {
        scanf("%d%d", &geese[0][i], &geese[1][i]);
        cpr[0].pb(geese[0][i]);
        cpr[1].pb(geese[1][i]);
    }
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d%d", &quads[0][i].f, &quads[1][i].f, &quads[0][i].s, &quads[1][i].s);
        cpr[0].pb(quads[0][i].f), cpr[0].pb(quads[0][i].s + 1);
        cpr[1].pb(quads[1][i].f), cpr[1].pb(quads[1][i].s + 1);
    }
    for (int i = 0; i < 2; i++) {
        cpr[i].pb(0);
        sort(cpr[i].begin(), cpr[i].end());
        cpr[i].erase(unique(cpr[i].begin(), cpr[i].end()), cpr[i].end());
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= K; j++) {
            quers[i][j] = {getIdxUpper(max(1, geese[i][j] - T), i) - 1, getIdxUpper(min(i == 0 ? N : M, geese[i][j] + T), i) - 1};
            geese[i][j] = getIdx(geese[i][j], i);
        }
        for (int j = 1; j <= Q; j++) {
            quads[i][j] = {getIdx(quads[i][j].f, i), getIdx(quads[i][j].s + 1, i)};
        }
    }
    
    solve(0, 1);
    solve(1, 0);
    printf("%lld\n", accumulate(ans + 1, ans + K + 1, 0LL));
    
    return 0;
}
