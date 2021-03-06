/*
 * Solution to Four Segments by Ava Pun
 * Key concepts: brute force, prefix sum array
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
const int MAX = 5005;

int N;
int arr[MAX];
ll pref[MAX];
int prefMax[MAX];

ll quer(int l, int r) {
    return pref[r - 1] - pref[l - 1];
}

ll calc(int i) {
    return quer(1, i) - quer(i, N + 1);
}

ll calc(int d1, int d2, int d3) {
    return quer(1, d1) - quer(d1, d2) + quer(d2, d3) - quer(d3, N + 1);
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i];
        pref[i] = arr[i] + pref[i - 1];
    }

    REV(i, N + 1, 1) {
        if (i == N + 1 || calc(prefMax[i + 1]) < calc(i)) prefMax[i] = i;
        else prefMax[i] = prefMax[i + 1];
    }

    int d1 = 0, d2 = 0, d3 = 0;
    ll best = -INFL;
    REP(i, 1, N) {
        REP(j, i, N) {
            int k = prefMax[j];
            ll tot = calc(i, j, k);
            if (tot > best) {
                best = tot;
                d1 = i, d2 = j, d3 = k;
            }
        }
    }

    cout << d1 - 1 << ' ' << d2 - 1 << ' ' << d3 - 1 << '\n';

}

