/*
 Solution to DMOPC '18 Contest 4 P4 - Dr. Henri and Lab Data by Ava Pun
 Key concepts: binary indexed tree, offline queries
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, Q;
pii arr[MAX];
ll bit[MAX], bitTot[MAX];
piii quers[MAX];
ll ans[MAX];

inline void upd(int x, int pos, ll bit[]) {
    for (int i = pos; i <= N; i += i & -i) {
        bit[i] += x;
    }
}

inline ll quer(int pos, ll bit[]) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline ll quer(int l, int r, ll bit[]) {
    return quer(r, bit) - quer(l - 1, bit);
}

int main() {
    
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i].f);
        arr[i].s = i;
        upd(arr[i].f, arr[i].s, bitTot);
    }
    sort(arr + 1, arr + N + 1);
    
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d", &quers[i].s.f, &quers[i].s.s, &quers[i].f.f);
        quers[i].f.s = i;
    }
    sort(quers + 1, quers + Q + 1);
    
    int idx = 1;
    for (int i = 1; i <= Q; i++) {
        int l = quers[i].s.f, r = quers[i].s.s, k = quers[i].f.f;
        while (idx <= N && arr[idx].f < k) {
            upd(arr[idx].f, arr[idx].s, bit);
            idx++;
        }
        ans[quers[i].f.s] = quer(l, r, bitTot) - 2 * quer(l, r, bit);
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
