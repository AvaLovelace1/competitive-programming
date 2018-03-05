/*
 Solution to DMOPC '14 Contest 8 P6 - Revenge of the Bins by Ava Pun
 Key concepts: segment tree with lazy propagation
 */
 
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int N;
int arr[MAX];
int tree[2 * MAX];
int lazy[2 * MAX];

void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]) + lazy[i];
    }
}

void update(int l, int r, int x) {
    l += N - 1;
    r += N - 1;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l & 1) {
            tree[l] += x;
            lazy[l] += x;
            l++;
        }
        if (!(r & 1)) {
            tree[r] += x;
            lazy[r] += x;
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    up(l0), up(r0);
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < N / 2; i++) {
        update(1, arr[i], 2);
        update(1, arr[i << 1], -1);
        update(1, arr[i << 1 | 1], -1);
        if (tree[1] >= 0) {
            ans = i + 1;
        }
    }
    printf("%d", ans);
    
    return 0;
}
