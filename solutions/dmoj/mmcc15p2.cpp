/*
 Solution to Akame by Ava Pun
 Key concepts: parallel binary search, convex hull of functions, segment tree
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
const int MAX = 5e5 + 5;
const double EPS = 1e-9;

int N, M, N1, H;
pair<double, double> arr[MAX];
pii pts[MAX];
pii rng[MAX], bounds[2][MAX];
vi events[MAX];
vi cpr;
int tree[2][2 * MAX];

inline int getIdx(int x) {
    return (int) (lower_bound(cpr.begin(), cpr.end(), x) - cpr.begin());
}

inline void down(int pos, int tree[]) {
    for (int sh = H; sh > 0; sh--) {
        int i = pos >> sh;
        if (tree[i] != 0) {
            tree[i << 1] = tree[i];
            tree[i << 1 | 1] = tree[i];
            tree[i] = 0;
        }
    }
}

inline void upd(int l, int r, int x, int tree[]) {
    if (l > r) {
        return;
    }
    l += N1 - 1, r += N1 - 1;
    down(l, tree), down(r, tree);
    while (l <= r) {
        if (l & 1) {
            tree[l] = x;
            l++;
        }
        if (!(r & 1)) {
            tree[r] = x;
            r--;
        }
        l >>= 1, r >>= 1;
    }
}

inline int quer(int pos, int tree[]) {
    pos += N1 - 1;
    down(pos, tree);
    return tree[pos];
}

inline double getY(int i, int pos) {
    return arr[i].f * cpr[pos] + arr[i].s;
}

inline void solve() {
    FILL(tree, 0);
    for (int i = 1; i <= N + 1; i++) {
        events[i].clear();
    }
    for (int i = 1; i <= M; i++) {
        events[(rng[i].f + rng[i].s) / 2].pb(i);
    }
    for (int i = 1; i <= N; i++) {
        upd(bounds[0][i].f, bounds[0][i].s, i, tree[0]);
        upd(bounds[1][i].f, bounds[1][i].s, i, tree[1]);
        for (int j : events[i]) {
            int idx = getIdx(pts[j].f);
            if (getY(quer(idx, tree[0]), idx) - EPS <= pts[j].s && getY(quer(idx, tree[1]), idx) + EPS >= pts[j].s) {
                rng[j].s = i;
            } else {
                rng[j].f = i + 1;
            }
        }
    }
}

inline int bs0l(int i) {
    int lo = 1, hi = N1 + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int best = quer(mid, tree[0]);
        if (getY(best, mid) > getY(i, mid) || arr[best].f < arr[i].f) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

inline int bs0r(int i) {
    int lo = 1, hi = N1 + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int best = quer(mid, tree[0]);
        if (getY(best, mid) < getY(i, mid) && arr[best].f < arr[i].f) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo - 1;
}

inline int bs1l(int i) {
    int lo = 1, hi = N1 + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int best = quer(mid, tree[1]);
        if (getY(best, mid) < getY(i, mid) || arr[best].f > arr[i].f) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

inline int bs1r(int i) {
    int lo = 1, hi = N1 + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int best = quer(mid, tree[1]);
        if (getY(best, mid) > getY(i, mid) && arr[best].f > arr[i].f) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo - 1;
}

int main() {

    scanf("%d%d", &N, &M);
    int a, b, c;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &a, &b, &c);
        arr[i] = {(double) -a / b, (double) c / b};
    }
    cpr.pb(-INF);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &pts[i].f, &pts[i].s);
        cpr.pb(pts[i].f);
    }
    sort(cpr.begin(), cpr.end());
    cpr.erase(unique(cpr.begin(), cpr.end()), cpr.end());
    N1 = (int) cpr.size() - 1;
    H = sizeof(int) * 8 - __builtin_popcount(N1);
    for (int i = 1; i <= M; i++) {
        rng[i] = {1, N + 1};
    }

    upd(1, N1, 1, tree[0]);
    upd(1, N1, 1, tree[1]);
    bounds[0][1] = bounds[1][1] = {1, N1};
    for (int i = 2; i <= N; i++) {
        bounds[0][i] = {bs0l(i), bs0r(i)};
        upd(bounds[0][i].f, bounds[0][i].s, i, tree[0]);
        bounds[1][i] = {bs1l(i), bs1r(i)};
        upd(bounds[1][i].f, bounds[1][i].s, i, tree[1]);
    }

    int L = (int) (log2(N + 1) + 1);
    for (int i = 1; i <= L; i++) {
        solve();
    }
    for (int i = 1; i <= M; i++) {
        printf("%d\n", rng[i].f == N + 1 ? -1 : rng[i].f);
    }

    return 0;
}
