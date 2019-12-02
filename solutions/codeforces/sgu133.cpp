/*
 Solution to Border by Ava Pun
 Key concepts: binary indexed tree, coordinate compression
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
const int MAX = 1e6 + 5;
const double EPS = 1e-9;

int N;
pii arr[16005];
int evs[2][32005];
vi cpr = {-1};
int bit[32005];

inline int getIdx(int n) {
    return (int) (lower_bound(cpr.begin(), cpr.end(), n) - cpr.begin());
}

inline void upd(int pos, int x) {
    for (int i = pos; i <= 2 * N; i += i & -i) {
        bit[i] += x;
    }
}

inline int quer(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
        cpr.pb(arr[i].f);
        cpr.pb(arr[i].s);
    }
    sort(cpr.begin(), cpr.end());

    for (int i = 1; i <= N; i++) {
        arr[i].f = getIdx(arr[i].f);
        arr[i].s = getIdx(arr[i].s);
        evs[1][arr[i].f] = arr[i].s;
        evs[0][arr[i].s] = arr[i].f;
    }

    int ans = 0;
    for (int i = 1; i <= 2 * N; i++) {
        if (evs[1][i] != 0) {
            upd(i, 1);
        }
        if (evs[0][i] != 0) {
            upd(evs[0][i], -1);
            if (quer(evs[0][i]) > 0) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
