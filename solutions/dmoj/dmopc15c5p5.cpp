/*
 Solution to DMOPC '15 Contest 5 P5 - World Line Convergence by Ava Pun
 Key concepts: binary indexed tree, Euler tour
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
const int MAX = 2e5 + 5;

int N;
int par[MAX];
vi adj[MAX];
int cnt = 0;
int in[MAX], out[MAX], bit[2 * MAX];
int ans[MAX];

inline void upd(int pos, int x) {
    for (int i = pos; i <= 2 * N; i += i & -i) {
        bit[i] = ((bit[i] + x) % MOD + MOD) % MOD;
    }
}

inline void upd(int l, int r, int x) {
    upd(l, x), upd(r + 1, -x);
}

inline int querUtil(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret = (ret + bit[i]) % MOD;
    }
    return ret;
}

inline int quer(int u) {
    return (querUtil(in[u]) - querUtil(out[u]) + MOD + 1) % MOD;
}

void dfs(int u) {
    in[u] = ++cnt;
    for (int v : adj[u]) {
        dfs(v);
    }
    out[u] = ++cnt;
}

int main() {

    scanf("%d", &N);
    int r = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &par[i]);
        adj[par[i]].pb(i);
        if (par[i] == 0) {
            r = i;
        }
    }
    dfs(r);
    int a;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        int q = quer(a);
        ans[a] = q;
        upd(1, in[par[a]], q);
    }
    for (int i = 1; i <= N; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
