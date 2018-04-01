/*
 Solution to CCO '13 P2 - Tourney by Ava Pun
 Key concepts: segment tree
 */
 
#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1048580];
int tree[2097155];

void build() {
    for (int i = N - 1; i > 0; i--) {
        tree[i] = arr[tree[i << 1]] > arr[tree[i << 1 | 1]] ? tree[i << 1] : tree[i << 1 | 1];
    }
}

void update(int pos, int x) {
    arr[pos] = x;
    pos += N - 1;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = arr[tree[i << 1]] > arr[tree[i << 1 | 1]] ? tree[i << 1] : tree[i << 1 | 1];
    }
}

int query(int pos) {
    int x = pos + N - 1;
    x >>= 1;
    int ans = 0;
    while (tree[x] == pos) {
        ans++;
        x >>= 1;
    }
    return ans;
}

int main() {
    
    int n;
    scanf("%d%d", &n, &M);
    N = pow(2, n);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        tree[i + N - 1] = i;
    }
    
    build();
    
    char c;
    int x, s;
    while (M--) {
        scanf(" %c", &c);
        if (c == 'R') {
            scanf("%d%d", &x, &s);
            update(x, s);
        } else if (c == 'W') {
            printf("%d\n", tree[1]);
        } else {
            scanf("%d", &x);
            printf("%d\n", query(x));
        }
    }
    
    return 0;
    
}
