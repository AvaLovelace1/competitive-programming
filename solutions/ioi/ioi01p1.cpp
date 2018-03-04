/*
 Solution to IOI '01 P1 - Mobile Phones by Ava Pun
 Key concepts: 2D binary indexed tree
 */
 
#include <bits/stdc++.h>

using namespace std;

int I, N, A, B, X, Y;
int bit[1025][1025];

void update(int r, int c, int x) {
    for (int i = r; i <= N; i += i & -i) {
        for (int j = c; j <= N; j += j & -j) {
            bit[i][j] += x;
        }
    }
}

int query(int r, int c) {
    int sum = 0;
    for (int i = r; i > 0; i -= i & -i) {
        for (int j = c; j > 0; j -= j & -j) {
            sum += bit[i][j];
        }
    }
    return sum;
}

int query(int r1, int c1, int r2, int c2) {
    return query(r2, c2) - query(r2, c1 - 1) - query(r1 - 1, c2) + query(r1 - 1, c1 - 1);
}

int main() {
    
    do {
        scanf("%d", &I);
        if (I == 0) {
            scanf("%d", &N);
        } else if (I == 1) {
            scanf("%d%d%d", &A, &B, &X);
            update(A + 1, B + 1, X);
        } else if (I == 2) {
            scanf("%d%d%d%d", &A, &B, &X, &Y);
            printf("%d\n", query(A + 1, B + 1, X + 1, Y + 1));
        }
    } while (I != 3);
    
    return 0;
}
