/*
 Solution to A Simple Task by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;
const double EPS = 1e-7;

int N, Q, H;
int seg[26][2 * MAX], lazy[26][MAX], sz[2 * MAX];

inline void init(int seg[]) {
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

inline void apply(int pos, int x, int seg[], int lazy[]) {
    seg[pos] = x * sz[pos];
    if (pos < N) {
        lazy[pos] = x;
    }
}

inline void up(int pos, int seg[], int lazy[]) {
    for (int i = pos / 2; i > 0; i /= 2) {
        if (lazy[i] != -1) {
            seg[i] = lazy[i] * sz[i];
        } else {
            seg[i] = seg[i * 2] + seg[i * 2 + 1]; 
        }
    }
}

inline void down(int pos, int seg[], int lazy[]) {
    for (int sh = H; sh > 0; sh--) {
        int i = pos >> sh;
        if (lazy[i] != -1) {
            apply(i * 2, lazy[i], seg, lazy);
            apply(i * 2 + 1, lazy[i], seg, lazy);
            lazy[i] = -1;
        }
    }
}

inline void upd(int l, int r, int x, int seg[], int lazy[]) {
    if (l > r) {
        return;
    }
    l += N - 1, r += N - 1;
    int l0 = l, r0 = r;
    down(l0, seg, lazy), down(r0, seg, lazy);
    while (l <= r) {
        if (l % 2 == 1) {
            apply(l, x, seg, lazy);
            l++;
        }
        if (r % 2 == 0) {
            apply(r, x, seg, lazy);
            r--;
        }
        l /= 2, r /= 2;
    }
    up(l0, seg, lazy), up(r0, seg, lazy);
}

inline int quer(int l, int r, int seg[], int lazy[]) {
    if (l > r) {
        return 0;
    }
    l += N - 1, r += N - 1;
    down(l, seg, lazy), down(r, seg, lazy);
    int ret = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            ret += seg[l];
            l++;
        }
        if (r % 2 == 0) {
            ret += seg[r];
            r--;
        }
        l /= 2, r /= 2;
    }
    return ret;
}

inline void printArr() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 26; j++) {
            if (quer(i, i, seg[j], lazy[j])) {
                printf("%c", 'a' + j);
            }
        }
    }
    printf("\n");
}

int main() {
    
    scanf("%d%d", &N, &Q);
    H = sizeof(int) * 8 - __builtin_clz(N);
    char c;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        seg[c - 'a'][i + N - 1] = 1;
        sz[i + N - 1] = 1;
    }
    for (int i = 0; i < 26; i++) {
        init(seg[i]);
    }
    FILL(lazy, -1);
    init(sz);

    int l, r, inc;
    while (Q--) {
        scanf("%d%d%d", &l, &r, &inc);
        if (inc) {
            int ptr = l;
            for (int i = 0; i < 26; i++) {
                int cnt = quer(l, r, seg[i], lazy[i]);
                upd(l, r, 0, seg[i], lazy[i]);
                upd(ptr, ptr + cnt - 1, 1, seg[i], lazy[i]);
                ptr += cnt;
            }
        } else {
            int ptr = r;
            for (int i = 0; i < 26; i++) {
                int cnt = quer(l, r, seg[i], lazy[i]);
                upd(l, r, 0, seg[i], lazy[i]);
                upd(ptr - cnt + 1, ptr, 1, seg[i], lazy[i]);
                ptr -= cnt;
            }
        }
    }

    printArr();
    
    return 0;
}
