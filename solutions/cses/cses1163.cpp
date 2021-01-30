/*
 * Solution to Traffic Lights by Ava Pun
 * Key concepts: implementation, ordered sets
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int X, N;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> N;
    multiset<int> lengths;
    lengths.insert(X);
    set<int> lights;
    lights.insert(0);
    lights.insert(X);

    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> p;
        auto it = lights.upper_bound(p);
        int ub = *it;
        --it;
        int lb = *it;
        lengths.erase(lengths.find(ub - lb));
        lengths.insert(ub - p);
        lengths.insert(p - lb);
        lights.insert(p);
        cout << *(--lengths.end()) << '\n';
    }

}
