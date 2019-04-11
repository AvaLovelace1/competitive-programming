/*
 Solution to WC18 #4 - Super Luigi Odyssey by Ava Pun
 Key concepts: merge sort segment tree, binary indexed tree, set, line sweep
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
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 250005;

int N, Q, K;
piii arr[MAX];
vector<ll> tree[2 * MAX];
ll bit[MAX];
vector<pair<ll, pii>> events;
set<int> pillars;

inline ll querBit(int pos) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
        ans %= MOD;
    }
    return ans;
}

inline ll querBit(int l, int r) {
    return (querBit(r) - querBit(l - 1) + MOD) % MOD;
}

inline void updBit(int pos, ll x) {
    x = (x - querBit(pos, pos) + MOD) % MOD;
    for (int i = pos; i <= N; i += i & -i) {
        bit[i] += x;
        bit[i] %= MOD; 
    }
}

// how many are greater than x within [l, r]?
inline int query(int l, int r, ll x) {
    if (l < 1) {
        l = 1;
    }
    l += N - 1, r += N - 1;
    int sum = 0;
    while (l <= r) {
        if (l & 1) {
            sum += (int) (tree[l].size() - (upper_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin()));
            l++;
        }
        if (!(r & 1)) {
            sum += (int) (tree[r].size() - (upper_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin()));
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return sum;
}

inline int bSearchL(int x, ll h, int n) {
    int lo = 1, hi = x, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (query(mid, x - 1, h) < n) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    lo--;
    return lo < 1 ? -1 : lo;
}

inline int bSearchR(int x, ll h, int n) {
    int lo = x + 1, hi = N + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (query(x + 1, mid, h) >= n) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo > N ? -1 : lo;
}

inline ll calcDist(int a, int b) {
    ll dist = arr[b].f.f - arr[a].f.f;
    return K == 1 ? dist : dist * dist % MOD;
}

int main() {
    
    scanf("%d%d%d", &N, &Q, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f.f, &arr[i].f.s);
        arr[i].s = i;
        arr[i].f.f++;
    }
    
    sort(arr + 1, arr + N + 1);
    int curPos = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i].s == 1) {
            curPos = i;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        tree[i + N - 1].pb(arr[i].f.s);
    }
    for (int i = N - 1; i > 0; i--) {
        merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), back_inserter(tree[i]));
    }
    
    ll ans = 0;
    ll lavaHeight = 0;
    int t, x;
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            lavaHeight += x;
            if (lavaHeight >= arr[curPos].f.s) {
                printf("-1\n");
                return 0;
            }
        } else {
            int nxtPos;
            if (t == 2) {
                nxtPos = bSearchL(curPos, lavaHeight, x);
            } else {
                nxtPos = bSearchR(curPos, lavaHeight, x);
            }
            if (nxtPos == -1) {
                printf("-1\n");
                return 0;
            }
            events.pb({lavaHeight, {min(curPos, nxtPos), max(curPos, nxtPos)}});
            curPos = nxtPos;
        }
    }

    for (int i = 1; i <= N; i++) {
        events.pb({arr[i].f.s, {-1, i}});
    }
    sort(events.begin(), events.end(), greater<pair<ll, pii>>());
    for (auto p : events) {
        if (p.s.f == -1) {
            // add pillar
            int x = p.s.s;
            pillars.insert(x);
            int pre = 0, nxt = 0;
            auto preIdx = pillars.lower_bound(x);
            auto nxtIdx = preIdx;
            ++nxtIdx;
            if (preIdx != pillars.begin()) {
                pre = *(--preIdx);
                updBit(pre, calcDist(pre, x));
            }
            if (nxtIdx != pillars.end()) {
                nxt = *(nxtIdx);
                updBit(x, calcDist(x, nxt)); 
            }
        } else {
            ans += querBit(p.s.f, p.s.s - 1);
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
