/*
 Solution to CCO '15 P3 - Solar Flight by Ava Pun
 Key concepts: segment tree, geometry
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
const int MAX = 2005;
const double EPS = 1e-9;

int X, K, N, Q;
piii arr[MAX];
vector<pair<double, ll>> events[MAX];
vector<ll> tree[MAX];

inline double intersect(piii a, piii b) {
    int ma = a.f.s - a.f.f;
    int mb = b.f.s - b.f.f;
    return (double) (a.f.f - b.f.f) * X / (mb - ma);
}

inline ll query(int pos, int l0, int r0) {
    pair<double, ll> p1 = {l0, -INFL}, p2 = {r0, INFL};
    int l = (int) (lower_bound(events[pos].begin(), events[pos].end(), p1) - events[pos].begin()) - 1;
    int r = (int) (upper_bound(events[pos].begin(), events[pos].end(), p2) - events[pos].begin()) - 1;
    l += events[pos].size(), r += events[pos].size();
    ll ret = 0;
    while (l <= r) {
        if (l & 1) {
            ret = max(ret, tree[pos][l]);
            l++;
        }
        if (!(r & 1)) {
            ret = max(ret, tree[pos][r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main() {

    scanf("%d%d%d%d", &X, &K, &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &arr[i].f.f, &arr[i].f.s, &arr[i].s.f);
        arr[i].s.s = i;
    }
    sort(arr + 1, arr + N + 1);
    ll sum = 0;
    for (int i = N; i >= 1; i--) {
        events[arr[i].s.s].pb({-EPS, sum});
        sum += arr[i].s.f;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i].f.s > arr[j].f.s) {
                double p = intersect(arr[i], arr[j]);
                events[arr[i].s.s].pb({p - EPS, -arr[j].s.f});
                events[arr[j].s.s].pb({p + EPS, arr[i].s.f});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        sort(events[i].begin(), events[i].end());
        tree[i].resize(events[i].size() * 2);
        ll sum = 0;
        for (int j = 0; j < events[i].size(); j++) {
            sum += events[i][j].s;
            tree[i][j + events[i].size()] = sum;
        }
        for (int j = events[i].size() - 1; j > 0; j--) {
            tree[i][j] = max(tree[i][j << 1], tree[i][j << 1 | 1]);
        }
    }

    int a, b;
    while (Q--) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", query(a, b, b + K));
    }

    return 0;
}
