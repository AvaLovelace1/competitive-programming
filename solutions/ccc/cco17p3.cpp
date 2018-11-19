/*
 Solution to CCO '17 P3 - Vera and Modern Art by Ava Pun
 Key concepts: binary indexed tree, bit tricks, line sweep, coordinate compression
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

const int NUM = sizeof(ll) * 8;
int N, Q;
int updatesAdd[MAX];
pii updatesX[MAX];
vector<ll> idxToVal;
piii updatesY[2 * MAX];
piii queries[MAX];
int answers[MAX];
int bit[3 * MAX];

inline int valToIdx(ll x) {
    return (int) (lower_bound(idxToVal.begin(), idxToVal.end(), x) - idxToVal.begin()) + 1;
}

inline void update(int pos, int x) {
    for (int i = pos; i < 3 * MAX; i += i & -i) {
        bit[i] += x;
    }
}

inline int query(int pos) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline ll rev(ll n) {
    ll n1 = 0;
    for (int i = 0; i < NUM - 1; i++) {
        n1 |= (ll) ((n & (ll) 1 << i) ? 1 : 0) << (NUM - 2 - i);
    }
    return n1;
}

inline pii conv(ll n) {
    ll a1 = rev(n), a2 = 0;
    a2 = a1 | (INT64_MAX >> (NUM - __builtin_clzll(n)));
    a1 &= ~((ll) 1 << (__builtin_clzll(n) - 1));
    a1 |= 1;
    return {a1, a2};
}

inline bool comp(piii a, piii b) {
    return a.first.second < b.first.second;
}

int main() {
    
    scanf("%d%d", &N, &Q);
    
    ll a, b;
    pii p;
    for (int i = 1; i <= N; i++) {
        scanf("%lld%lld%d", &a, &b, &updatesAdd[i]);
        updatesX[i] = conv(a);
        idxToVal.push_back(updatesX[i].first);
        idxToVal.push_back(updatesX[i].second);
        pii p = conv(b);
        updatesY[i] = {{p.first, 1}, i};
        updatesY[i + N] = {{p.second, 0}, i};
    }
    
    sort(updatesY + 1, updatesY + 2 * N + 1);
    
    for (int i = 1; i <= Q; i++) {
        scanf("%lld%lld", &a, &b);
        queries[i].first.first = rev(a);
        idxToVal.push_back(queries[i].first.first);
        queries[i].first.second = rev(b);
        queries[i].second = i;
    }
    sort(queries + 1, queries + Q + 1, comp);
    
    sort(idxToVal.begin(), idxToVal.end());
    idxToVal.erase(unique(idxToVal.begin(), idxToVal.end()), idxToVal.end());
    
    int idx = 1;
    for (int i = 1; i <= Q; i++) {
        while (updatesY[idx].first.first <= queries[i].first.second && idx <= 2 * N) {
            int j = updatesY[idx].second;
            if (updatesY[idx].first.second) {
                update(valToIdx(updatesX[j].first), updatesAdd[j]);
                update(valToIdx(updatesX[j].second) + 1, -updatesAdd[j]);
            } else {
                update(valToIdx(updatesX[j].first), -updatesAdd[j]);
                update(valToIdx(updatesX[j].second) + 1, updatesAdd[j]);
            }
            idx++;
        }
        answers[queries[i].second] = query(valToIdx(queries[i].first.first));
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%d\n", answers[i]);
    }
    
    return 0;
    
}
