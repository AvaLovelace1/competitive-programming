/*
 ~ Binary Indexed (Fenwick) Tree Data Structure ~
 
 Like a segtree, but only works for operations that are reversible.
 Doesn't support range updates unless you want to be really fancy.
 Also much faster and simpler to type, and uses half as much memory.
 
 Time complexity:
 Build - O(N)
 Range update - O(logN)
 Range query - O(logN)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, Q;
int arr[MAX], bit[MAX];

void update(int pos, int add) {
    arr[pos] += add;
    for (int i = pos; i <= N; i += i & -i) {
        bit[i] += add;
    }
}

void build() {
    for (int i = 1; i <= N; i++) {
        update(i, arr[i]);
    }
}

int query(int pos) {
    int sum = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    build();
    
    scanf("%d", &Q);
    char c;
    int a, b;
    while (Q--) {
        scanf(" %c", &c);
        if (c == 'U') {
            scanf("%d%d", &a, &b);
            update(a, b);
        } else if (c == 'Q') {
            scanf("%d%d", &a, &b);
            printf("Sum from %d to %d: %d\n", a, b, query(a, b));
        }
    }
    
    return 0;
    
}

