/*
 Solution to JOI '14 - Fortune Telling 2 by Ava Pun
 Key concepts: binary indexed tree, segment tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, K;
pii arr[MAX], ops[MAX];
int itov[MAX];
unordered_map<int, int> idx;
int K1 = 0;
int bit[MAX], tree[2 * MAX];

void ubit(int pos, int x) {
    for (int i = pos; i <= K; i += i & -i) {
        bit[i] += x;
    }
}

int qbit(int pos) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

int qbit(int l, int r) {
    return qbit(r) - qbit(l - 1);
}

int qtree(int l, int r) {
    l += K1 - 1, r += K1 - 1;
    int ans = -1;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = max(ans, tree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

bool comp(pii a, pii b) {
    return max(a.f, a.s) > max(b.f, b.s);
}

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    sort(arr + 1, arr + N + 1, comp);
    
    for (int i = 1; i <= K; i++) {
        scanf("%d", &ops[i].f);
        ops[i].s = i;
        idx[ops[i].f] = i;
    }
    sort(ops + 1, ops + K + 1);
    
    for (int i = 1; i <= K; i++) {
        if (ops[i] != ops[i - 1]) {
            K1++;
            itov[K1] = ops[i].f;
        }
    }
    
    for (int i = 1; i <= K1; i++) {
        tree[i + K1 - 1] = idx[itov[i]];
    }
    for (int i = K1 - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
    
    ll ans = 0;
    int itr = K;
    
    for (int i = 1; i <= N; i++) {
        
        int mn = min(arr[i].f, arr[i].s), mx = max(arr[i].f, arr[i].s);
        while (itr > 0 && ops[itr].f >= mx) {
            ubit(ops[itr].s, 1);
            itr--;
        }
        
        int l = (int) (lower_bound(itov + 1, itov + K1 + 1, mn) - itov);
        int r = (int) (lower_bound(itov + 1, itov + K1 + 1, mx) - itov) - 1;
        int pos = qtree(l, r), n = qbit(pos + 1, K);
        int add = 0;
        
        if (pos != -1) {
            add = n % 2 == 1 ? mn : mx;
        } else {
            if (arr[i].f == mx) {
                add = n % 2 == 1 ? mn : mx;
            } else {
                add = n % 2 != 1 ? mn : mx;
            }
        }
        ans += add;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
