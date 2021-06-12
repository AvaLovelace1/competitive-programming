/*
 Solution to CCO '21 P2 - Weird Numeral System by Ava Pun
 Key concepts: dynamic programming, BFS, math
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
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

struct Solver {
    using ll = long long;
    using vi = vector<int>;

    int K, Q, D, M;
    vector<vi> digitsMod;
    unordered_map<ll, int> trace;

    Solver(int K, int Q, int D, int M, vi &digits):
        K{K}, Q{Q}, D{D}, M{M}, digitsMod(K) {
        for (auto d : digits) {
            digitsMod[(d % K + K) % K].push_back(d);
        }
    }

    void bfs(ll n) {
        queue<ll> q;
        q.push(n);
        if (n != 0) trace[n] = 0;
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            for (auto d : digitsMod[(u % K + K) % K]) {
                ll v = (u - d) / K;
                if (trace.find(v) == trace.end()) {
                    trace[v] = d;
                    q.push(v);
                    if (v == 0) return;
                }
            }
        }
    }

    bool possible(ll n) {
        trace.clear();
        bfs(n);
        return trace.find(0) != trace.end();
    }

    void solve(ll n) {
        trace.clear();
        bfs(n);
        if (trace.find(0) == trace.end()) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        ll u = 0;
        do {
            ll v = u * K + trace[u];
            cout << trace[u] << " \n"[v == n];
            u = v;
        } while (u != n);
    }
};

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int K, Q, D, M;
    cin >> K >> Q >> D >> M;
    vi digits(D);
    REP(i, 0, D - 1) cin >> digits[i];
    auto solver = Solver(K, Q, D, M, digits);

    REP(i, 1, Q) {
        ll n;
        cin >> n;
        solver.solve(n);
    }

}
