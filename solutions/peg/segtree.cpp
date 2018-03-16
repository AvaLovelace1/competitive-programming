/*
 Solution to Segment Tree Test by Ava Pun
 Key concepts: segment tree
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
int tree[200005];

void build(int pos) {
    tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
}

void update(int pos, int x) {
    pos += N;
    tree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        build(i);
    }
}

int query(int l, int r) {
    l += N, r += N;
    int ans = INT_MAX;
    while (l <= r) {
        if (l & 1) {
            ans = min(ans, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = min(ans, tree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[i + N]);
    }
    
    for (int i = N - 1; i > 0; i--) {
        build(i);
    }
    
    char c;
    int a, b;
    while (M--) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'Q') {
            printf("%d\n", query(a, b));
        } else {
            update(a, b);
        }
    }
    
    return 0;
}
