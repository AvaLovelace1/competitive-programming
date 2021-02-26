/*
 * Solution to USACO '16 Open G2 - Closing the Farm by Ava Pun
 * Key concepts: disjoint set, graph theory
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
int quers[MAX];
bool alive[MAX];
bool ans[MAX];

template<int MAX> struct DSU {
    int N;
    int par[MAX], rnk[MAX], sz[MAX];

    DSU(int N): N{N}, par{}, rnk{}, sz{} {
        for (int i = 1; i <= N; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int findSet(int u) {
        if (par[u] == u) return u;
        else return par[u] = findSet(par[u]);
    }

    bool sameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    bool join(int a, int b) {
        a = findSet(a), b = findSet(b);
        if (a == b) return 0;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        if (rnk[a] == rnk[b]) ++rnk[a];
        return 1;
    }
};

int main() {

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 1, M) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    REP(i, 1, N) {
        cin >> quers[i];
    }

    auto *dsu = new DSU<MAX>{N};
    int tot = 0;
    REV(i, N, 1) {
        int u = quers[i];
        alive[u] = 1;
        ++tot;
        TRAV(v, adj[u]) {
            if (alive[v]) {
                dsu->join(u, v);
            }
        }
        if (dsu->sz[dsu->findSet(u)] == tot) {
            ans[i] = 1;
        }
    }

    REP(i, 1, N) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }

}

