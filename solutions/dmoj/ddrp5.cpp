/*
 Solution to Double Doors Regional P5 - Tudor Eats Ice Cream Cones by Ava Pun
 Key concepts: segment tree
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
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, Q;
int ROOT;
int arr[MAX];
pii maxTree[2 * MAX], minTree[2 * MAX];

inline void combMax(pii &a, pii &b, pii &x) {
    int rnk[4] = {a.f, a.s, b.f, b.s};
    sort(rnk, rnk + 4);
    x = {rnk[3], rnk[2]};
}

inline void updMax(int pos, int x) {
    pos += N - 1;
    maxTree[pos] = {x, -INF};
    for (int i = pos >> 1; i > 0; i >>= 1) {
        combMax(maxTree[i << 1], maxTree[i << 1 | 1], maxTree[i]);
    }
}

inline void combMin(pii &a, pii &b, pii &x) {
    int rnk[4] = {a.f, a.s, b.f, b.s};
    sort(rnk, rnk + 4);
    x = {rnk[1], rnk[0]};
}

inline void updMin(int pos, int x) {
    pos += N - 1;
    minTree[pos] = {x, INF};
    for (int i = pos >> 1; i > 0; i >>= 1) {
        combMin(minTree[i << 1], minTree[i << 1 | 1], minTree[i]);
    }
}

inline int querMax(int l, int r) {
    l += N - 1, r += N - 1;
    pii ans = {-INF, -INF};
    while (l <= r) {
        if (l & 1) {
            combMax(maxTree[l], ans, ans);
            l++;
        }
        if (!(r & 1)) {
            combMax(maxTree[r], ans, ans);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans.f + ans.s;
}

inline int querMin(int l, int r) {
    l += N - 1, r += N - 1;
    pii ans = {INF, INF};
    while (l <= r) {
        if (l & 1) {
            combMin(minTree[l], ans, ans);
            l++;
        }
        if (!(r & 1)) {
            combMin(minTree[r], ans, ans);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans.f + ans.s;
}

inline void upd(int pos, int x) {
    updMax(pos, x), updMin(pos, x);
}

inline pii toIdx(int n) {
    return {n * ROOT - ROOT + 1, n * ROOT};
}

int main() {

    scanf("%d%d", &N, &Q);
    ROOT = sqrt(N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        maxTree[i + N - 1] = {arr[i], -INF};
        minTree[i + N - 1] = {arr[i], INF};
    }
    for (int i = N - 1; i > 0; i--) {
        combMax(maxTree[i << 1], maxTree[i << 1 | 1], maxTree[i]);
        combMin(minTree[i << 1], minTree[i << 1 | 1], minTree[i]);
    }
    
    int ans = 0;
    int t, a, b;
    while (Q--) {
        scanf("%d%d%d", &t, &a, &b);
        a ^= ans, b ^= ans;
        if (t == 1) {
            upd(a, b);
        } else {
            int idxL = toIdx(a).f, idxR = toIdx(b).s;
            ans = t == 2 ? querMin(idxL, idxR) : querMax(idxL, idxR);
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
