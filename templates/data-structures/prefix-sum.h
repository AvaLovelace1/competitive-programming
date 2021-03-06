template<class T, int MAX> struct PSA {
    int N;
    T arr[MAX + 2];

    PSA(int N): N{N}, arr{} {}

    PSA(int N, T a[]): N{N}, arr{} {
        for (int i = 1; i <= N; ++i) {
            arr[i] = a[i];
        }
    }

    void differentiate() {
        for (int i = N; i >= 1; --i) {
            arr[i] -= arr[i - 1];
        }
    }

    void integrate() {
        for (int i = 1; i <= N; ++i) {
            arr[i] += arr[i - 1];
        }
    }

    void upd(int l, int r, T x) {
        arr[l] += x;
        arr[r + 1] -= x;
    }

    T quer(int l, int r) {
        return arr[r] - arr[l - 1];
    }
};
