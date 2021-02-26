/*
 * Solution to USACO '17 January G1 - Balanced Photo by Ava Pun
 * Key concepts: binary indexed tree, coordinate compression
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

int N;
int arr[MAX];

template<typename T> struct CC {
    vector<T> coords;
    CC(): coords{} {}
    void add(T x) {
        coords.push_back(x);
    }
    void compress() {
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
    }
    int idxOf(T x) {
        return (int) (lower_bound(coords.begin(), coords.end(), x) - coords.begin()) + 1;
    }
};

template<typename T, int MAX> struct Fenwick {
    int N;
    T arr[MAX + 2], tree[MAX + 2];

    Fenwick(int N): N{N}, arr{}, tree{} {}

    Fenwick(int N, T a[]): N{N}, arr{}, tree{} {
        for (int i = 1; i <= N; ++i) {
            upd(i, a[i]);
        }
    }

    void upd(int pos, T x) {
        T add = x;
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

int main() {

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;

    auto *cc = new CC<int>();
    REP(i, 1, N) {
        cin >> arr[i];
        cc->add(arr[i]);
    }
    cc->compress();

    auto *fenL = new Fenwick<int, MAX>(N);
    auto *fenR = new Fenwick<int, MAX>(N);
    REP(i, 1, N) {
        fenR->upd(cc->idxOf(arr[i]), 1);
    }

    int ans = 0;
    REP(i, 1, N) {
        fenR->upd(cc->idxOf(arr[i]), -1);
        int lCnt = fenL->quer(cc->idxOf(arr[i]) + 1, N);
        int rCnt = fenR->quer(cc->idxOf(arr[i]) + 1, N);
        if (lCnt > 2 * rCnt || rCnt > 2 * lCnt) {
            ++ans;
        }
        fenL->upd(cc->idxOf(arr[i]), 1);
    }
    cout << ans << '\n';

}

