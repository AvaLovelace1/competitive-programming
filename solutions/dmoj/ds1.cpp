/*
 Solution to Binary Indexed Tree Test by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MAX = 1e5 + 5;

int N, M;
int arr[MAX];
ll bit[MAX];
int bitCounts[MAX];

void update(int idx, int old, int x) {
    int add = x - old;
    arr[idx] = x;
    for (int i = idx; i <= N; i += i & -i) {
        bit[i] += add;
    }
}

void updateCount(int old, int x) {
    for (int i = x; i <= 100000; i += i & -i) {
        bitCounts[i]++;
    }
    for (int i = old; i != 0 && i <= 100000; i += i & -i) {
        bitCounts[i]--;
    }
}

void build() {
    for (int i = 1; i <= N; i++){
        update(i, 0, arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        updateCount(0, arr[i]);
    }
}

ll sumQuery(int x) {
    ll sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}

ll sumQuery(int l, int r) {
    return sumQuery(r) - sumQuery(l - 1);
}

int countQuery(int n) {
    int sum = 0;
    for (int i = n; i > 0; i -= i & -i) {
        sum += bitCounts[i];
    }
    return sum;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    build();
    
    char c;
    for (int i = 1; i <= M; i++) {
        scanf(" %c", &c);
        if (c == 'C') {
            int x, v;
            scanf("%d%d", &x, &v);
            int old = arr[x];
            update(x, old, v);
            updateCount(old, v);
        } else if (c == 'S') {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", sumQuery(l, r));
        } else {
            int v;
            scanf("%d", &v);
            printf("%d\n", countQuery(v));
        }
    }
    
    return 0;
    
}
