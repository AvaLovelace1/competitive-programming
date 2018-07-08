/*
 Solution to DMOPC '17 Contest 5 P5 - XOR Bridges by Ava Pun
 Key concepts: disjoint set, graph theory
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
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, M, Q;
int arr[MAX];
int par[MAX], ranks[MAX];
vi vec;

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

inline void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else if (ranks[b] < ranks[a]) {
        par[b] = a;
    } else {
        par[b] = a;
        ranks[a]++;
    }
}

inline int hsb(int n) {
    return 31 - __builtin_clz(n);
}

void solve(vi v, int n) {
    if (v.empty()) {
        return;
    }
    if (n == -1) {
        for (int i : v) {
            Union(v[0], i);
        }
        return;
    }
    vi va, vb;
    for (int i : v) {
        if (arr[i] & (1 << n)) {
            va.pb(i);
        } else {
            vb.pb(i);
        }
    }
    if (M & (1 << n)) {
        for (int i : va) {
            Union(va[0], i);
        }
        for (int i : vb) {
            Union(vb[0], i);
            va.pb(i);
        }
        vb.clear();
    }
    v.clear();
    solve(va, n - 1), solve(vb, n - 1);
}

int main() {
    
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        par[i] = i;
        vec.pb(i);
    }
    int n = hsb(M);
    for (int i : vec) {
        n = max(n, hsb(arr[i]));
    }
    solve(vec, n);
    
    int p, q;
    while (Q--) {
        scanf("%d%d", &p, &q);
        printf(Find(p) == Find(q) ? "YES\n" : "NO\n");
    }
    
    return 0;
}
