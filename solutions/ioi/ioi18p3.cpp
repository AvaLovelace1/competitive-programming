/*
 Solution to IOI '18 P3 - Werewolf by Ava Pun
 Key concepts: disjoint set, Euler tour, binary lifting, line sweep, binary indexed tree
 */

#include "werewolf.h"

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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const int MAXL = 18;

int NN, Q;
vi adj[MAX], tree[2][MAX];
int dsuPar[2][MAX], par[2][20][MAX];
int in[2][MAX], out[2][MAX], tour[2][MAX];
int cnt = -1;
vector<piii> events[2][MAX];
int bit[MAX];

int Find(int x, bool t) {
    if (dsuPar[t][x] != x) {
        dsuPar[t][x] = Find(dsuPar[t][x], t);
    }
    return dsuPar[t][x];
}

inline void Union(int u, int v, bool t) {
    v = Find(v, t);
    u = Find(u, t);
    if (u == v) {
        return;
    }
    dsuPar[t][v] = u;
    tree[t][u].pb(v);
    par[t][0][v] = u;
}

void dfs(int u, bool t) {
    cnt++;
    in[t][u] = cnt;
    tour[t][cnt] = u;
    for (int v : tree[t][u]) {
        dfs(v, t);
    }
    out[t][u] = cnt;
}

inline void upd(int pos, int x) {
    pos++;
    for (int i = pos; i <= NN; i += i & -i) {
        bit[i] += x;
    }
}

inline int quer(int pos) {
    pos++;
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline int quer(int l, int r) {
    return quer(r) - quer(l - 1);
}

std::vector<int> check_validity(int N, std::vector<int> X, std::vector<int> Y,
                                std::vector<int> S, std::vector<int> E,
                                std::vector<int> L, std::vector<int> R) {

    NN = N;
    
    for (int i = 0; i < X.size(); i++) {
        adj[X[i]].pb(Y[i]);
        adj[Y[i]].pb(X[i]);
    }
    
    // Build a tree where the LCA of u and v is the min (max)
    // bottleneck of all paths from u to v.
    // Just do the disjoint set thing, but make it into a tree.
    for (int i = 0; i < N; i++) {
        dsuPar[0][i] = dsuPar[1][i] = i;
    }
    par[0][0][0] = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j : adj[i]) {
            if (j > i) {
                Union(i, j, 0);
            }
        }
    }
    par[1][0][N - 1] = N - 1;
    for (int i = 0; i < N; i++) {
        for (int j : adj[i]) {
            if (j < i) {
                Union(i, j, 1);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= MAXL; j++) {
            for (int k = 0; k < N; k++) {
                par[i][j][k] = par[i][j - 1][par[i][j - 1][k]];
            }
        }
    }
    
    // Compute Euler tours
    dfs(0, 0);
    cnt = -1;
    dfs(N - 1, 1);
    
    Q = S.size();
    std::vector<int> A(Q);
    
    // Compute the largest (smallest) ancestor A of S (E) that stays
    // within L (R) bounds. Everything in the subtree of A
    // can be reached from S (E).
    for (int i = 0; i < Q; i++) {
        int u = S[i], v = E[i];
        for (int j = MAXL; j >= 0; j--) {
            if (par[0][j][u] >= L[i]) {
                u = par[0][j][u];
            }
            if (par[1][j][v] <= R[i]) {
                v = par[1][j][v];
            }
        }
        events[1][in[0][u]].pb({i, {in[1][v], out[1][v]}});
        events[0][out[0][u]].pb({i, {in[1][v], out[1][v]}});
    }
    
    // Line sweep
    // Keep all points seen so far in the BIT. When you reach the end
    // of a rectangle, add all points in the range. When you reach the
    // start of a rectangle, subtract all points in the range.
    for (int i = 0; i < N; i++) {
        for (auto p : events[1][i]) {
            A[p.f] -= quer(p.s.f, p.s.s);
        }
        upd(in[1][tour[0][i]], 1);
        for (auto p : events[0][i]) {
            A[p.f] += quer(p.s.f, p.s.s);
        }
    }
    for (int i = 0; i < Q; ++i) {
        A[i] = (A[i] > 0);
    }
    return A;
}
