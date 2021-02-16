template<int MAX> struct DSU {
    int N;
    int par[MAX], rnk[MAX];

    DSU(int N): N{N}, par{}, rnk{} {
        for (int i = 1; i <= N; ++i) {
            par[i] = i;
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
        if (rnk[a] == rnk[b]) ++rnk[a];
        return 1;
    }
};
