/*
 * Solution to USACO '20 December S2 - Rectangular Pasture by Ava Pun
 * Key concepts: 2D prefix sum array
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2505;
const double EPS = 1e-9;

int N;
pii arr[MAX];
int pref[MAX][MAX];

vi sortedx, sortedy;

int quer(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int get(int y) {
    return (int) (lower_bound(sortedy.begin(), sortedy.end(), y) - sortedy.begin());
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    sortedx.pb(-1);
    sortedy.pb(-1);
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f >> arr[i].s;
        sortedy.pb(arr[i].s);
    }

    sort(arr + 1, arr + N + 1);
    sort(sortedy.begin(), sortedy.end());

    for (int i = 1; i <= N; ++i) {
        int y = get(arr[i].s);
        pref[i][y] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            pref[i][j] += pref[i][j - 1] + pref[i - 1][j];
            pref[i][j] -= pref[i - 1][j - 1];
        }
    }

    ll ans = 1; 

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            int x1 = i;
            int x2 = j;
            int y1 = get(min(arr[i].s, arr[j].s));
            int y2 = get(max(arr[i].s, arr[j].s));
            ans += (ll) (quer(x1, y2 + 1, x2, N) + 1) * (quer(x1, 1, x2, y1 - 1) + 1);
        }
    }

    cout << ans << '\n';

}

