/*
 Solution to WC18 #3 - Counterpicking by Ava Pun
 Key concepts: convex hull, binary search
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
const int MAX = 3e5 + 5;

int N, M;
pii arr[MAX], arr2[MAX];
stack<pii> h1, h2;
vii v;

ll orientation(pii a, pii b, pii c) {
    return (ll) (b.s - a.s) * (c.f - b.f) - (ll) (c.s - b.s) * (b.f - a.f);
}

void process(pii p, stack<pii> &st) {
    bool cw = false;
    while (st.size() > 1 && !cw) {
        pii b = st.top();
        st.pop();
        pii a = st.top();
        if (orientation(a, b, p) > 0) {
            cw = true;
            st.push(b);
        }
    }
    st.push(p);
}

void hull() {
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        process(arr[i], h1);
    }
}

inline ll query(int a, int b) {
    return v[a].f * arr2[b].f + v[a].s * arr2[b].s;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld", &arr[i].f, &arr[i].s);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%lld%lld", &arr2[i].f, &arr2[i].s);
    }
    hull();
    
    while (!h1.empty()) {
        v.pb(h1.top());
        h1.pop();
    }
    
    for (int i = 0; i < M; i++) {
        int lo = 0, hi = (int) v.size() - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (query(mid, i) >= query(mid + 1, i)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        printf("%lld\n", query(lo, i));
    }
    
    return 0;
}
