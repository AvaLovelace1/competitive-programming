/*
 Solution to CCC '11 S3 - Alice Through the Looking Glass by Ava Pun
 Key concepts: recursion
 */

#include <bits/stdc++.h>

using namespace std;

int T;
bool grid[5][5] = {{0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

bool solve(int m, int x, int y) {
    if (m == 1) {
        return grid[y][x];
    } else {
        int x1 = x / pow(5, m - 1);
        int y1 = y / pow(5, m - 1);
        if ((x1 == 1 && y1 == 1) || (x1 == 2 && y1 == 2) || (x1 == 3 && y1 == 1)) {
            return solve(m - 1, x % (int) pow(5, m - 1), y % (int) pow(5, m - 1));
        } else {
            return grid[y1][x1];
        }
    }
}

int main() {

    scanf("%d", &T);
    int m, x, y;
    while (T--) {
        scanf("%d%d%d", &m, &x, &y);
        printf(solve(m, x, y) ? "crystal\n" : "empty\n");
    }
    
    return 0;
    
}
