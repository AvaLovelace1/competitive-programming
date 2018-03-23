/*
 Solution to Back to School '16: Textbooks by Ava Pun
 Key concepts: segment tree with lazy propagation
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

int N, h, N1;
piii arr[MAX];
unordered_set<int> coords;
unordered_map<int, int> idx;
ll sumTree[4 * MAX];
int maxTree[4 * MAX], size[4 * MAX], lazy[2 * MAX];

void apply(int pos, int x) {
    maxTree[pos] = x;
    sumTree[pos] = (ll) x * size[pos] % MOD;
    if (pos < N1) {
        lazy[pos] = x;
    }
}

void down(int pos) {
    for (int s = h; s > 0; s--) {
        int i = pos >> s;
        if (lazy[i]) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        if (lazy[i]) {
            maxTree[i] = lazy[i];
            sumTree[i] = (ll) lazy[i] * size[i] % MOD;
        } else {
            maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1]);
            sumTree[i] = sumTree[i << 1] + sumTree[i << 1 | 1] % MOD;
        }
        
    }
}

void update(int l, int r, int x) {
    l += N1, r += N1;
    int l0 = l, r0 = r;
    down(l0), down(r0);
    while (l <= r) {
        if (l & 1) {
            apply(l, x);
            l++;
        }
        if (!(r & 1)) {
            apply(r, x);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    up(l0), up(r0);
}

int queryMax(int l, int r) {
    l += N1, r += N1;
    down(l), down(r);
    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, maxTree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = max(ans, maxTree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

ll querySum(int l, int r) {
    l += N1, r += N1;
    down(l), down(r);
    ll ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += sumTree[l];
            ans %= MOD;
            l++;
        }
        if (!(r & 1)) {
            ans += sumTree[r];
            ans %= MOD;
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int main() {
    
    scanf("%d", &N);
    int s, l, w;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &s, &l, &w);
        arr[i] = {s, {l, w}};
        coords.insert(s);
        coords.insert(s + l);
    }
    vector<int> v(coords.begin(), coords.end());
    sort(v.begin(), v.end());
    N1 = (int) v.size();
    h = 8 * sizeof(int) - __builtin_clz(N1);
    
    for (int i = 0; i < N1; i++) {
        idx[v[i]] = i;
    }
    for (int i = N1; i < 2 * N1 - 1; i++) {
        size[i] = v[i - N1 + 1] - v[i - N1];
    }
    size[2 * N1 - 1] = 1;
    for (int i = N1 - 1; i > 0; i--) {
        size[i] = size[i << 1] + size[i << 1 | 1];
    }
    
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        s = arr[i].first;
        l = arr[i].second.first;
        w = arr[i].second.second;
        int l0 = idx[s], r0 = idx[s + l] - 1;
        int maxN = queryMax(l0, r0);
        ans += ((ll) maxN * l % MOD - querySum(l0, r0) + MOD) % MOD;
        ans %= MOD;
        update(l0, r0, maxN + w);
    }
    printf("%lld", ans);

    return 0;
}
