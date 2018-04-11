/*
 Solution to VM7WC '15 #5 Gold - Tree Planting by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2001;
const int MOD = 1e9 + 7;
int N;
int tree[MAX][MAX];

void update(int r, int c, int x) {
    int dist = r + c;
    for (int i = c; i <= dist; i += i & -i) {
        tree[dist][i] += x;
        tree[dist][i] %= MOD;
    }
}

int query(int r, int c) {
    int dist = r + c;
    int sum = 0;
    for (int i = c; i > 0; i -= i & -i) {
        sum += tree[dist][i];
        sum %= MOD;
    }
    return sum;
}

int query(int r, int c, int x) {
    return (query(r - x, c + x) - query(r + 1, c - 1) + MOD) % MOD;
}

int main() {
    
    scanf("%d", &N);

    int t, r, c, x, total = 0;
    while (N--) {
        scanf("%d%d%d%d", &t, &r, &c, &x);
        if (t == 1) {
            update(r, c, x);
        } else {
            total += query(r, c, x);
            total %= MOD;
        }
    }
    
    printf("%d", total);
    
    return 0;
    
}
