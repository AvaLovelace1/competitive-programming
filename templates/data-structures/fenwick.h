template<typename T, int MAX> struct Fenwick {
    int N;
    T arr[MAX + 2], tree[MAX + 2];

    Fenwick(int N): N{N}, arr{}, tree{} {}

    Fenwick(int N, T a[]): N{N}, arr{}, tree{} {
        for (int i = 1; i <= N; i++) {
            upd(i, a[i]);
        }
    }

    void upd(int pos, T x) {
        T add = x - arr[pos];
        arr[pos] = x;
        for (int i = pos; i <= N; i += i & -i) {
            tree[i] += add;
        }
    }

    T quer(int pos) {
        T sum = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    T quer(int l, int r) {
        return quer(r) - quer(l - 1);
    }
};
