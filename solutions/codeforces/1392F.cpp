/*
 * Solution to Omkar and Landslide by Ava Pun
 * Key concepts: greedy algorithms, constructive algorithms, math
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
const int MAX = 1e6 + 5;

int N;
ll arr[MAX];

ll sumToN(ll n) {
    return n * (n + 1) / 2;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i];
    }
    
    ll tot = accumulate(arr + 1, arr + N + 1, 0LL);
    ll base = sumToN(N - 1);
    ll fullLayers = (tot - base) / N;
    ll lastLayer = (tot - base) % N;

    REP(i, 1, N) {
        cout << (i - 1) + fullLayers + (i <= lastLayer) << " \n"[i == N];
    }

}

