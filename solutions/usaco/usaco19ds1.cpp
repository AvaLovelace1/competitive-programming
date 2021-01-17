/*
 * Solution to USACO '19 December S1 - MooBuzz by Ava Pun
 * Key concepts: binary search
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
const int MAX = 52;

int N;

bool check(ll n) {
    ll moo = n / 3 + n / 5 - n / 15;
    return n - moo >= N;
}

int main() {

    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ll lo = 1, hi = INFL;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';

}
