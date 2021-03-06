/*
 * Solution to Save Energy! by Ava Pun
 * Key concepts: mathematics, implementation
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

ll K, D, T;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> K >> D >> T;

    T *= 2;
    ll ans = 0;

    ll cycleLen = (K + D - 1) / D * D;
    ll minsOffPerCycle = cycleLen - K;

    ll progressPerCycle = 2*K + minsOffPerCycle;
    ll fullCycles = T / progressPerCycle;
    ans += fullCycles * cycleLen * 2;

    ll remProgress = T % progressPerCycle;
    ll onProgress = 2*K;
    ans += min(remProgress, onProgress);
    remProgress -= min(remProgress, onProgress);
    ans += remProgress * 2;

    cout << fixed << setprecision(1) << (double) ans / 2.0 << '\n';

}

