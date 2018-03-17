/*
 Solution to USACO '13 January G3 - Seating by Ava Pun
 Key concepts: segment tree with lazy propagation
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
const int MAX = 5e5 + 5;

int N0, N, M, h;
int pref[4 * MAX], suff[4 * MAX], tot[4 * MAX], size[4 * MAX];
int lazy[2 * MAX];

int getVal(int pos, int arr[]) {
    if (lazy[pos]) {
        return size[pos] * (lazy[pos] == -1);
    } else {
        return arr[pos];
    }
}

void apply(int pos, int x) {
    pref[pos] = suff[pos] = tot[pos] = size[pos] * (x == -1);
    if (pos < N) {
        lazy[pos] = x;
    }
}

void up(int pos) {
    pref[pos] = pref[pos << 1] == size[pos << 1] ? pref[pos << 1] + pref[pos << 1 | 1] : pref[pos << 1];
    suff[pos] = suff[pos << 1 | 1] == size[pos << 1 | 1] ? suff[pos << 1 | 1] + suff[pos << 1] : suff[pos << 1 | 1];
    tot[pos] = max(suff[pos << 1] + pref[pos << 1 | 1], max(tot[pos << 1], tot[pos << 1 | 1]));
    if (lazy[pos]) {
        pref[pos] = suff[pos] = tot[pos] = size[pos] * (lazy[pos] == -1);
    }
}

void down(int i) {
    if (lazy[i]) {
        apply(i << 1, lazy[i]);
        apply(i << 1 | 1, lazy[i]);
        lazy[i] = 0;
    }
}

void pushDown(int pos) {
    for (int ss = h; ss > 0; ss--) {
        int i = pos >> ss;
        down(i);
    }
}

void pushUp(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        up(i);
    }
}

void update(int l, int r, int x) {
    
    l += N - 1, r += N - 1;
    int l0 = l, r0 = r;
    pushDown(l0), pushDown(r0);
    
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
    pushUp(l0), pushUp(r0);
}

int query(int pos, int x) {
    if (pos < N) {
        down(pos);
        if (getVal(pos << 1, tot) >= x) {
            return query(pos << 1, x);
        } else if (getVal(pos << 1, suff) + getVal(pos << 1 | 1, pref) >= x && getVal(pos << 1, suff) != 0) {
            return size[pos << 1] - getVal(pos << 1, suff) + 1;
        } else {
            return size[pos << 1] + query(pos << 1 | 1, x);
        }
    } else {
        return 1;
    }
}

int main() {
    
    scanf("%d%d", &N0, &M);
    N = 1 << (sizeof(int) * 8 - __builtin_clz(N0));
    h = sizeof(int) * 8 - __builtin_clz(N);

    for (int i = N; i < 2 * N; i++) {
        pref[i] = suff[i] = tot[i] = size[i] = 1;
    }
    for (int i = N - 1; i > 0; i--) {
        size[i] = size[i << 1] + size[i << 1 | 1];
        up(i);
    }
    
    char c;
    int a, b;
    int ans = 0;
    while (M--) {
        scanf(" %c", &c);
        if (c == 'A') {
            scanf("%d", &a);
            if (tot[1] < a) {
                ans++;
            } else {
                int q = query(1, a);
                if (q + a - 1 <= N0) {
                    update(q, q + a - 1, 1);
                } else {
                    ans++;
                }
            }
        } else {
            scanf("%d%d", &a, &b);
            update(a, b, -1);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
