/*
 Solution to Rest In The Shades by Ava Pun
 Key concepts: geometry, binary search
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
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int Y, A, B, N, Q;
pii segs[MAX];
int pref[MAX];

inline int query(int l, int r) {
    return pref[r] - pref[l - 1];
}

inline double findX(int segPt, pii pt, double k) {
    return pt.f + k * (segPt - pt.f);
}

inline int bSearch(pii pt, int x, double k) {
    int lo = 1, hi = N + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (x < findX(segs[mid].s, pt, k)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

inline bool contain(pii seg, int x, pii pt, double k) {
    return x > findX(seg.f, pt, k) && x < findX(seg.s, pt, k);
}

int main() {
    
    scanf("%d%d%d", &Y, &A, &B);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &segs[i].f, &segs[i].s);
        pref[i] = pref[i - 1] + segs[i].s - segs[i].f;
    }
    
    scanf("%d", &Q);
    pii pt;
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d", &pt.f, &pt.s);
        double k = (double) (pt.s - Y) / pt.s;
        double ans = query(1, N) * k;
        int l = bSearch(pt, A, k), r = bSearch(pt, B, k);
        if (contain(segs[l], A, pt, k)) {
            ans += findX(segs[l].s, pt, k) - A;
            l++;
        }
        if (contain(segs[r], B, pt, k)) {
            ans += B - findX(segs[r].f, pt, k);
        }
        ans -= query(1, l - 1) * k, ans -= query(r, N) * k;
        printf("%.15lf\n", ans);
    }
    
    return 0;
}
