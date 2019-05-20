/*
 Solution to DMOPC '15 Contest 3 P5 - Total Annihilation by Ava Pun
 Key concepts: bitmask brute force, meet in the middle
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e4 + 5;

int N[2];
int arr[2][40];
vector<ll> vals[3];

int main() {

    scanf("%d%d", &N[0], &N[1]);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    bool lrg = N[1] > N[0];
    for (int i = 0; i < 2; i++) {
        for (int m = 0; m < (1 << min(18, N[i])); m++) {
            ll tot = 0;
            for (int j = 0; j < min(18, N[i]); j++) {
                if (m & (1 << j)) {
                    tot += arr[i][j];
                }
            }
            vals[i].pb(tot);
        }
        sort(vals[i].begin(), vals[i].end());
    }
    for (int m = 0; m < (1 << max(0, N[lrg] - 18)); m++) {
        ll tot = 0;
        for (int j = 0; j < N[lrg] - 18; j++) {
            if (m & (1 << j)) {
                tot += arr[lrg][j + 18];
            }
        }
        vals[2].pb(tot);
    }
    sort(vals[2].begin(), vals[2].end());

    ll ans = 0;
    for (ll i : vals[!lrg]) {
        if (i > 0) {
            for (ll j : vals[2]) {
                ans += (ll) (upper_bound(vals[lrg].begin(), vals[lrg].end(), i - j) - lower_bound(vals[lrg].begin(), vals[lrg].end(), i - j));
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
