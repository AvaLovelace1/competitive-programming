template<typename T, T (*comb)(T, T), T zeroVal, void (*update)(T&, T), int MAX> struct Segtree {
    int N;
    T tree[2 * MAX];

    Segtree(int N): N{N}, tree{} {}

    Segtree(int N, T a[]): N{N}, tree{} {
        for (int i = 1; i <= N; ++i) {
            tree[i + N - 1] = a[i];
        }
        for (int i = N - 1; i > 0; --i) {
            tree[i] = comb(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void upd(int pos, T x) {
        pos += N - 1;
        update(tree[pos], x);
        for (int i = pos / 2; i > 0; i /= 2) {
            tree[i] = comb(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T quer(int l, int r) {
        l += N - 1, r += N - 1;
        T ret = zeroVal;
        while (l <= r) {
            if (l % 2) {
                ret = comb(ret, tree[l]);
                l++;
            }
            if (!(r % 2 == 1)) {
                ret = comb(ret, tree[r]);
                r--;
            }
            l /= 2, r /= 2;
        }
        return ret;
    }
};
