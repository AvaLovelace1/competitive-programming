/*
 Solution to DMOPC '15 Contest 1 P6 - Lelei and Contest by Ava Pun
 Key concepts: segment tree with lazy propagation, Fermat's Little Theorem
 */
 
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int M, N, Q, h;
int tree[2 * MAX];
int lazy[MAX];
int size[2 * MAX];

void build() {
    for (int i = N - 1; i > 0; i--) {
        tree[i] = (tree[i << 1] + tree[i << 1 | 1]) % M;
        size[i] = size[i << 1] + size[i << 1 | 1];
    }
}

void apply(int pos, int x) {
    tree[pos] += ((x % M) * (size[pos] % M)) % M;
    tree[pos] %= M;
    if (pos < N) {
        lazy[pos] += x % M;
        lazy[pos] %= M;
    }
}

void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = (((tree[i << 1] + tree[i << 1 | 1]) % M) + (lazy[i] * (size[i] % M)) % M) % M;
    }
}

void down(int pos) {
    for (int s = h; s > 0; s--) {
        int i = pos >> s;
        if (lazy[i] != 0) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

void update(int l, int r, int x) {
    l += N - 1;
    r += N - 1;
    int l0 = l, r0 = r;
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

int query(int l, int r) {
    l += N - 1;
    r += N - 1;
    down(l);
    down(r);
    int sum = 0;
    while (l <= r) {
        if (l & 1) {
            sum += tree[l];
            sum %= M;
            l++;
        }
        if (!(r & 1)) {
            sum += tree[r];
            sum %= M;
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return sum;
}

int main() {

    scanf("%d%d%d", &M, &N, &Q);
    h = sizeof(int) * 8 - __builtin_clz(N);
    int x;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        tree[i + N] = x % M;
        size[i + N] = 1;
    }
    
    build();
    
    int t, l, r;
    while (Q--) {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            scanf("%d", &x);
            update(l, r, x);
        } else {
            printf("%d\n", query(l, r));
        }
    }
    
    return 0;
}
