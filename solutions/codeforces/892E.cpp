/*
 * Solution to Mahmoud and Ehab and the function by Ava Pun
 * Key concepts: set
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N, M, Q;
ll arr[MAX], brr[MAX];
set<ll> f;

void calcF() {
    ll totA = accumulate(arr + 1, arr + N + 1, 0LL);
    ll totB = accumulate(brr + 1, brr + N + 1, 0LL);
    f.insert(totA + totB);
    for (int i = 1; i <= M - N; ++i) {
        totB += brr[N + i];
        totB -= brr[i];
        ll ans = totB;
        if (i % 2 == 1) {
            ans *= -1;
        }
        f.insert(totA + ans);
    }
}

ll solve(ll baseline) {
    auto it = f.upper_bound(baseline);
    ll ub = (it != f.end() ? *it : INFL) - baseline;
    ll lb = (it != f.begin() ? *(--it) : -INFL) - baseline;
    return min(abs(ub), abs(lb));
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        if (i % 2 == 0) {
            arr[i] *= -1;
        }
    }
    for (int i = 1; i <= M; ++i) {
        cin >> brr[i];
        if (i % 2 == 1) {
            brr[i] *= -1;
        }
    }

    calcF();

    cout << solve(0) << '\n';

    int l, r, x;
    ll baseline = 0;
    for (int i = 1; i <= Q; ++i) {
        cin >> l >> r >> x;
        int len = r - l + 1;
        if (len % 2 != 0) {
            if (l % 2 == 1) {
                baseline -= x;
            } else {
                baseline += x;
            }
        }
        cout << solve(baseline) << '\n';
    }

}
