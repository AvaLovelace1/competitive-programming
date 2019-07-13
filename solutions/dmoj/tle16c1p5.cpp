/*
 Solution to TLE '16 Contest 1 P5 - Battle Plan by Ava Pun
 Key concepts: graph theory, segment tree
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
int arr[MAX];
vii adj[MAX];
ll ans[MAX];
int minTree[2 * MAX];
ll sumTree[2 * MAX];
int node[MAX];

inline void updMin(int pos, int x) {
    pos += N - 1;
    minTree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1 | 1]);
    }
}

inline void updSum(int pos, int x) {
    pos += N - 1;
    sumTree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        sumTree[i] = sumTree[i << 1] + sumTree[i << 1 | 1];
    }
}

inline int querMin(int l, int r) {
    l += N - 1; r += N - 1;
    int ret = INF;
    while (l <= r) {
        if (l & 1) {
            ret = min(ret, minTree[l]);
            l++;
        }
        if (!(r & 1)) {
            ret = min(ret, minTree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ret;
}

inline ll querSum(int l, int r) {
    if (l < 1) {
        l++;
    }
    l += N - 1; r += N - 1;
    ll ret = 0;
    while (l <= r) {
        if (l & 1) {
            ret += sumTree[l];
            l++;
        }
        if (!(r & 1)) {
            ret += sumTree[r];
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ret;
}

inline int bsearch(int r) {
    int lo = 1, hi = r, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (querMin(mid, r) >= arr[node[r]]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo - 1;
}

void solve(int u, int dep) {
    updMin(dep, arr[u]);
    node[dep] = u;
    int d = bsearch(dep);
    ans[u] = ans[node[d]] + querSum(d, dep - 1) * arr[u];
    for (pii e : adj[u]) {
        int v = e.f, w = e.s;
        updSum(dep, w);
        solve(v, dep + 1);
        updSum(dep, 0);
    }
    updMin(dep, INF);
    node[dep] = 0;
}

int main() {

    scanf("%d", &N);
    int a, d;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d%d", &a, &d, &arr[i]);
        adj[a].pb({i, d});
    }
    FILL(minTree, INF);
    solve(N, 1);
    for (int i = 1; i < N; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
