/*
 * Solution to Spy Detected! by Ava Pun
 * Key concepts: brute force, implementation
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
const int MAX = 2e5 + 5;

int T, N;
int arr[MAX];

int solve() {
    if (arr[1] != arr[2] && arr[2] == arr[3]) return 1;
    REP(i, 2, N) if (arr[i] != arr[i - 1]) return i;
    return -1;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(t, 1, T) {
        cin >> N;
        REP(i, 1, N) cin >> arr[i];
        cout << solve() << '\n';
    }

}
