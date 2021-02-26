/*
 * Solution to Greg and Array by Ava Pun
 * Key concepts: difference array
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

int N, M, K;
ll arr[MAX];
piii ops[MAX];

template<class T, int MAX> struct PSA {
    int N;
    T arr[MAX + 2];

    PSA(int N): N{N} {
        fill(arr, arr + N + 2, 0);
    }

    PSA(int N, T a[]): N{N} {
        arr[0] = arr[N + 1] = 0;
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

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> K;
    REP(i, 1, N) {
        cin >> arr[i];
    }

    REP(i, 1, M) {
        int l, r, d;
        cin >> l >> r >> d;
        ops[i] = {{l, r}, d};
    }

    auto *psaQuers = new PSA<int, MAX>(M);
    REP(i, 1, K) {
        int l, r;
        cin >> l >> r;
        psaQuers->upd(l, r, 1);
    }
    psaQuers->integrate();

    auto *psa = new PSA<ll, MAX>(N, arr);
    psa->differentiate();
    REP(i, 1, M) {
        int nTimes = psaQuers->arr[i];
        int l = ops[i].f.f, r = ops[i].f.s;
        ll tot = (ll) nTimes * ops[i].s;
        psa->upd(l, r, tot);
    }
    psa->integrate();

    REP(i, 1, N) {
        cout << psa->arr[i] << " \n"[i == N];
    }

}

