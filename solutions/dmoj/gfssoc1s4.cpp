/*
 Solution to Stalactites by Ava Pun
 Key concepts: 3D binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int N, Q;
int arr[251][251][251];
ll tree[251][251][251];

ll query(int x, int y, int z) {
    ll sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            for (int k = z; k > 0; k -= k & -k) {
                sum += tree[i][j][k];
            }
        }
    }
    return sum;
}

ll query(int x1, int x2, int y1, int y2, int z1, int z2) {
    return query(x2, y2, z2) - query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1) + query(x1 - 1, y1 - 1, z2)
        + query(x1 - 1, y2, z1 - 1) + query(x2, y1 - 1, z1 - 1) - query(x1 - 1, y1 - 1, z1 - 1);
}

void update(int x, int y, int z, int n) {
    int add = n - arr[x][y][z];
    arr[x][y][z] = n;
    for (int i = x; i <= N; i += i & -i) {
        for (int j = y; j <= N; j += j & -j) {
            for (int k = z; k <= N; k += k & -k) {
                tree[i][j][k] += add;
            }
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &Q);
    
    char c;
    int x1, x2, y1, y2, z1, z2, n;
    ll sum = 0;
    while (Q--) {
        scanf(" %c", &c);
        scanf("%d%d%d", &x1, &y1, &z1);
        if (c == 'C') {
            scanf("%d", &n);
            update(x1, y1, z1, n);
        } else {
            scanf("%d%d%d", &x2, &y2, &z2);
            sum += query(x1, x2, y1, y2, z1, z2);
        }
    }
    
    printf("%lld", sum);
    
    return 0;
    
}
