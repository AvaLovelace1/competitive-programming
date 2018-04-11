/*
 Solution to TSOC '15 Contest 2 #6 - All-Out War! by Ava Pun
 Key concepts: segment tree with lazy propagation
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q, h;
long long int tree[60005];
int lazy[30005];

void build() {
    for (int i = N - 1; i > 0; i--) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }
}

void build(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]) + lazy[i];
        if (tree[i] < 0) {
            tree[i] = 0;
        }
    }
}

void apply(int pos, int add) {
    tree[pos] += add;
    if (tree[pos] < 0) {
        tree[pos] = 0;
    }
    if (pos < N) {
        lazy[pos] += add;
    }
}

void push(int pos) {
    for (int s = h; s > 0; s--) {
        int i = pos >> s;
        if (lazy[i] != 0) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

void update(int l, int r, int add) {
    l += N;
    r += N;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l & 1) {
            apply(l, add);
            l++;
        }
        if (!(r & 1)) {
            apply(r, add);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    build(l0);
    build(r0);
}

long long int query(int l, int r) {
    l += N;
    r += N;
    push(l);
    push(r);
    long long int minN = INT_MAX;
    while (l <= r) {
        if (l & 1) {
            minN = min(minN, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            minN = min(minN, tree[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return minN;
}

int main() {

    scanf("%d%d", &N, &Q);
    
    for (int i = 0; i < N; i++) {
        scanf("%lld", &tree[N + i]);
    }
    
    h = log2(N);
    build();
    
    int l, r, x;
    while (Q--) {
        scanf("%d%d%d", &l, &r, &x);
        update(l - 1, r - 1, -x);
        printf("%lld %lld\n", query(l - 1, r - 1), query(0, N - 1));
    }
    
    return 0;
}
