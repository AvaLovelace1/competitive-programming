template<typename T, int MAX_N, int MAX_M> struct Fenwick2D {
    int N, M;
    T arr[MAX_N + 2][MAX_M + 2], tree[MAX_N + 2][MAX_M + 2];

    Fenwick2D(int N, int M): N{N}, M{M}, arr{}, tree{} {}

    Fenwick2D(int N, int M, T a[][MAX_M]): N{N}, M{M}, arr{}, tree{} {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                upd(i, j, a[i][j]);
            }
        }
    }

    void upd(int r, int c, T x) {
        T add = x - arr[r][c];
        arr[r][c] = x;
        for (int i = r; i <= N; i += i & -i) {
            for (int j = c; j <= M; j += j & -j) {
                tree[i][j] += add;
            }
        }
    }

    T quer(int r, int c) {
        T sum = 0;
        for (int i = r; i > 0; i -= i & -i) {
            for (int j = c; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    T quer(int r1, int c1, int r2, int c2) {
        return quer(r2, c2) - quer(r1 - 1, c2) - quer(r2, c1 - 1) + quer(r1 - 1, c1 - 1);
    }
};
