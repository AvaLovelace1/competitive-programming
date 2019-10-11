/*
 Solution to Inversions by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 70000;
const double EPS = 1e-9;

int N, M;
int arr[MAX];
ll bit[MAX];
vi cpr;

inline int getIdx(int x) {
    return (int) (lower_bound(cpr.begin(), cpr.end(), x) - cpr.begin());
}

inline void upd(int pos, int x) {
    for (int i = pos; i <= M; i += i & -i) {
        bit[i] += x;
    }
}

inline ll quer(int pos) {
    ll ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}

inline ll quer(int l, int r) {
    return quer(r) - quer(l - 1);
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        cpr.pb(arr[i]);
    }
    cpr.pb(-1);
    sort(cpr.begin(), cpr.end());
    cpr.erase(unique(cpr.begin(), cpr.end()), cpr.end());
    M = cpr.size() - 1;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += quer(getIdx(arr[i]) + 1, M);
        upd(getIdx(arr[i]), 1);
    }
    printf("%lld\n", ans);

    return 0;
}
