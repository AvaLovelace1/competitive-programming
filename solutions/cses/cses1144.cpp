/*
 * Solution to Salary Queries by Ava Pun
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
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 2e5 + 5;

int N, Q;
int arr[MAX];
piii quers[MAX];

vi cp;
int idxOf(int x) {
    return (int) (lower_bound(ALL(cp), x) - cp.begin()) + 1;
}

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

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> Q;
    REP(i, 1, N) {
        cin >> arr[i];
        cp.pb(arr[i]);
    }
    REP(i, 1, Q) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '!') {
            quers[i] = {0, {a, b}};
            cp.pb(b);
        } else {
            quers[i] = {1, {a, b}};
            cp.pb(a);
            cp.pb(b);
        }
    }
    sort(ALL(cp));
    cp.erase(unique(ALL(cp)), cp.end());

    auto *fen = new Fenwick<int, 3 * MAX>((int) cp.size());
    REP(i, 1, N) {
        fen->upd(idxOf(arr[i]), 1);
    }

    REP(i, 1, Q) {
        int a = quers[i].s.f, b = quers[i].s.s;
        if (quers[i].f == 0) {
            fen->upd(idxOf(arr[a]), -1);
            arr[a] = b;
            fen->upd(idxOf(arr[a]), 1);
        } else {
            cout << fen->quer(idxOf(a), idxOf(b)) << '\n';
        }
    }

}

