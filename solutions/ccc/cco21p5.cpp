/*
 Solution to CCO '21 P5 - Bread First Search by Ava Pun
 Key concepts: dynamic programming, segment tree with lazy propagation
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
const int MAX = 2e5 + 5;

int N, M;
vi adj[MAX];
int dp[MAX];

int h;
int tree[2 * MAX], lazy[MAX];

void apply(int pos, int x) {
    tree[pos] += x;
    if (pos < N) {
        lazy[pos] += x;
    }
}

void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]) + lazy[i];
    }
}

void down(int pos) {
    for (int s = h; s > 0; s--) {
        int i = pos >> s;
        if (lazy[i]) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

void update(int l, int r, int x) {
    l += N - 1, r += N - 1;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l & 1) apply(l++, x);
        if (!(r & 1)) apply(r--, x);
        l >>= 1, r >>= 1;
    }
    up(l0), up(r0);
}

int query(int l, int r) {
    l += N - 1, r += N - 1;
    down(l), down(r);
    int ret = INF;
    while (l <= r) {
        if (l & 1) ret = min(ret, tree[l++]);
        if (!(r & 1)) ret = min(ret, tree[r--]);
        l >>= 1, r >>= 1;
    }
    return ret;
}

int solve() {
    FILL(dp, INF);

    int maxE = 0;
    int j = 0;
    dp[1] = 0;
    REP(i, 2, N) {
        while (j < i && maxE <= i) {
            ++j;
            TRAV(k, adj[j]) maxE = max(maxE, k);
        }
        update(1, min(i, adj[i].empty() ? INF : *adj[i].begin()) - 1, 1);
        dp[i] = query(1, j - 1);
        update(i, i, dp[i]);
    }

    return dp[N];
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 1, M) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    REP(i, 1, N) sort(ALL(adj[i]));
    h = (int) (sizeof(int) * 8 - __builtin_clz(N));

    cout << solve() << '\n';

}