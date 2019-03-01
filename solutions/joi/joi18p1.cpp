/*
 Solution to JOI '18 P1 - Bubble Sort 2 by Ava Pun
 Key concepts: binary indexed tree, segment tree with lazy propagation
 */

#include "bubblesort2.h"

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MAX = 5e5 + 5;

int N, N1, Q, H;
int arr[MAX], bit[2 * MAX], tree[4 * MAX], lazy[2 * MAX];
piii cpress[2 * MAX];

inline void updBit(int pos, int x) {
    pos++;
    for (int i = pos; i <= N1; i += i & -i) {
        bit[i] += x;
    }
}

inline int querBit(int pos) {
    pos++;
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline void apply(int pos, int x) {
    tree[pos] += x;
    if (pos < N1) {
        lazy[pos] += x;
    }
}

inline void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]) + lazy[i];
    }
}

inline void updTree(int l, int r, int x) {
    l += N1, r += N1;
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

inline int querTree(int pos) {
    pos += N1;
    for (int k = H; k > 0; k--) {
        int i = pos >> k;
        if (lazy[i]) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
    return tree[pos];
}

void update(int pos, int x) {
    int x0 = arr[pos];
    arr[pos] = x;
    updBit(x0, -1), updBit(x, 1);
    updTree(x0, x0, -INF - querTree(x0)), updTree(x, x, (pos - (querBit(x) - 1)) - querTree(x));
    if (x0 < x) {
        updTree(x0 + 1, x - 1, 1);
    } else {
        updTree(x + 1, x0 - 1, -1);
    }
}

std::vector<int> countScans(std::vector<int> A,std::vector<int> X,std::vector<int> V) {

    N = (int) A.size();
    Q = (int) X.size();
    for (int i = 0; i < N; i++) {
        arr[i] = A[i];
    }

    for (int i = 0; i < N; i++) {
        cpress[i] = {{arr[i], i}, i};
    }
    for (int i = 0; i < Q; i++) {
        cpress[i + N] = {{V[i], X[i]}, i + N};
    }
    sort(cpress, cpress + N + Q);
    int rnk = 0;
    for (int i = 0; i < N + Q; i++) {
        if (cpress[i].s < N) {
            arr[cpress[i].s] = rnk;
        } else {
            V[cpress[i].s - N] = rnk;
        }
        if (cpress[i + 1] > cpress[i]) {
            rnk++;
        }
    }
    N1 = rnk + 1;
    H = sizeof(int) * 8  - __builtin_clz(N1);

    fill(tree, tree + 2 * N1, -INF);
    for (int i = 0; i < N; i++) {
        updBit(arr[i], 1);
    }
    for (int i = 0; i < N; i++) {
        tree[arr[i] + N1] = i - (querBit(arr[i]) - 1);
    }
    for (int i = N1 - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    std::vector<int> answer(Q);
    for (int i = 0; i < Q; i++) {
        update(X[i], V[i]);
        answer[i] = tree[1];
    }

    return answer;
}
