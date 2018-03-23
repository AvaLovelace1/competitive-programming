/*
 Solution to MWC '15 #4 P3: Salt by Ava Pun
 Key concepts: implementation, map
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;
map<int, int> xcoords;
map<int, int> ycoords;
map< int, map<int, bool> > coords;

int main() {
    
    scanf("%d%d", &N, &Q);
    int x, a, b;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &a, &b);
        coords[a][b] = true;
        xcoords[a]++;
        ycoords[b]++;
    }

    char c;
    while (Q--) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d%d", &a, &b);
            if (coords[a][b]) {
                printf("salty");
            } else {
                printf("bland");
            }
        } else {
            scanf(" %c%d", &c, &a);
            if (c == 'X') {
                printf("%d", xcoords[a]);
            } else {
                printf("%d", ycoords[a]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
