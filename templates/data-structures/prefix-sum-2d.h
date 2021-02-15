template<class T, int MAX_N, int MAX_M> struct PSA2D {
    int N, M;
    T arr[MAX_N + 2][MAX_M + 2];

    PSA2D(int N, int M): N{N}, M{M}, arr{} {}

    PSA2D(int N, int M, T a[][MAX_M]): N{N}, M{M}, arr{} {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                arr[i][j] = a[i][j];
            }
        }
    }

    void differentiate() {
        for (int i = N; i >= 1; --i) {
            for (int j = M; j >= 1; --j) {
                arr[i][j] -= arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
    }

    void integrate() {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
    }

    void upd(int r1, int c1, int r2, int c2, T x) {
        arr[r1][c1] += x;
        arr[r1][c2 + 1] -= x;
        arr[r2 + 1][c1] -= x;
        arr[r2 + 1][c2 + 1] += x;
    }

    T quer(int r1, int c1, int r2, int c2) {
        return arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1];
    }
};
