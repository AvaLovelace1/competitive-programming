/*
 * Solution to Google Code Jam '21 QR P1 - Reversort by Ava Pun
 * Key concepts: implementation
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

int T, N;
int arr[MAX];

ll go() {
    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i];
    }

    ll ans = 0; 
    REP(i, 1, N - 1) {
        int j = (int) (min_element(arr + i, arr + N + 1) - arr);
        reverse(arr + i, arr + j + 1);
        ans += j - i + 1;
    }
    return ans;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(i, 1, T) {
        cout << "Case #" << i << ": " << go() << '\n';
    }

}

