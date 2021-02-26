/*
 * Solution to Road Construction by Ava Pun
 * Key concepts: disjoint set
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
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
const int MAX = 1e5 + 5;

int N, M;
int arr[MAX];

template<int MAX> struct DSU {
    int N;
    int par[MAX], rnk[MAX], sz[MAX];

    int nComps;
    int mxComp;

    DSU(int N): N{N}, par{}, rnk{}, sz{}, nComps{N}, mxComp{1} {
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
        mxComp = max(mxComp, sz[a]);
        if (rnk[a] == rnk[b]) ++rnk[a];
        --nComps;
        return 1;
    }
};

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    auto *dsu = new DSU<MAX>(N);

    REP(i, 1, M) {
        int u, v;
        cin >> u >> v;
        dsu->join(u, v);
        cout << dsu->nComps << ' ' << dsu->mxComp << '\n';
    }

}

