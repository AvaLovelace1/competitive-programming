/*
 Solution to BOI 2011 P5 - Time Is Money by Ava Pun
 Key concepts: minimum spanning tree, geometry
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<piii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

int N, M;
int x[MAX], y[MAX], t[MAX], c[MAX];
pii edges[MAX];
bool chosen[MAX], bestChosen[MAX];
int par[205], ranks[205];
int bestT = INT_MAX, bestC = INT_MAX;
ll best = INT64_MAX;

inline int orient(pii a, pii b, pii c) {
    ll val = (b.s - a.s) * (c.f - b.f) - (b.f - a.f) * (c.s - b.s);
    if (val == 0) {
        return 0;
    } else {
        return val > 0 ? 1 : -1;
    }
}

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

inline bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return 0;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
    return 1;
}

inline pii krus() {
    
    FILL(chosen, 0), FILL(ranks, 0);
    for (int i = 0; i < N; i++) {
        par[i] = i;
    }
    sort(edges, edges + M);
    
    int cnt = 0;
    for (int i = 0; i < M && cnt < N - 1; i++) {
        ll idx = edges[i].s;
        int u = x[idx], v = y[idx];
        if (Union(u, v)) {
            chosen[idx] = 1;
            cnt++;
        }
    }
    
    int totT = 0, totC = 0;
    for (int i = 0; i < M; i++) {
        if (chosen[i]) {
            totT += t[i], totC += c[i];
        }
    }
    ll ans = (ll) totT * totC;
    if (ans < best) {
        best = ans, bestT = totT, bestC = totC;
        for (int i = 0; i < M; i++) {
            bestChosen[i] = chosen[i];
        }
    }
    return {totT, totC};
}

void solve(pii a, pii b) {
    for (int i = 0; i < M; i++) {
        edges[i] = {t[i] * (a.s - b.s) + c[i] * (b.f - a.f), i};
    }
    pii p = krus();
    if (orient(a, p, b) < 0) {
        solve(a, p), solve(p, b);
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &x[i], &y[i], &t[i], &c[i]);
    }
    
    for (int i = 0; i < M; i++) {
        edges[i] = {t[i], i};
    }
    pii a = krus();
    for (int i = 0; i < M; i++) {
        edges[i] = {c[i], i};
    }
    pii b = krus();
    solve(a, b);
    
    printf("%d %d\n", bestT, bestC);
    for (int i = 0; i < M; i++) {
        if (bestChosen[i]) {
            printf("%d %d\n", x[i], y[i]);
        }
    }
    
    return 0;
}
