/*
 Solution to COCI '15 Contest 2 #5 Vudu by Ava Pun
 Key concepts: binary indexed tree, prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, int> pii;
const int MAX = 1e6 + 5;

int N, P;
pii pref[MAX];
int bit[MAX];

void update(ll pos) {
    for (ll i = pos; i <= N + 1; i += i & -i) {
        bit[i]++;
    }
}

ll query(ll pos) {
    ll ans = 0;
    for (ll i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

bool comp(pii a, pii b) {
    return a.second < b.second;
}

int main() {
    
    scanf("%d", &N);
    pref[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &pref[i].first);
        pref[i].second = i;
    }
    scanf("%d", &P);
    for (int i = 1; i <= N; i++) {
        pref[i].first += pref[i - 1].first - P;
    }
    
    sort(pref, pref + N + 1);
    int rank = 1;
    ll prev = pref[0].first;
    pref[0].first = 1;
    for (int i = 1; i <= N; i++) {
        if (pref[i].first > prev) {
            rank++;
        }
        prev = pref[i].first;
        pref[i].first = rank;
    }
    sort(pref, pref + N + 1, comp);
    
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += query(pref[i].first);
        update(pref[i].first);
    }
    
    printf("%lld", ans);
    
    return 0;
    
}
