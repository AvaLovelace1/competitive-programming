/*
 Solution to Checkerboard Summation (Easy) by Ava Pun
 Key concepts: 2D prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int board[3005][3005];
pair<int, int> pref[3005][3005];

int main() {
    
    scanf("%d%d", &M, &N);
    
    int r, c, x;
    scanf("%d%d%d", &r, &c, &x);
    while (r != 0) {
        board[r][c] = x;
        scanf("%d%d%d", &r, &c, &x);
    }
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if ((i & 1) == (j & 1)) {
                pref[i][j].first = board[i][j];
                pref[i][j].second = 0;
            } else {
                pref[i][j].first = 0;
                pref[i][j].second = board[i][j];
            }
            if (i - 1 > 0) {
                pref[i][j].first += pref[i - 1][j].first;
                pref[i][j].second += pref[i - 1][j].second;
                if (j - 1 > 0) {
                    pref[i][j].first -= pref[i - 1][j - 1].first;
                    pref[i][j].second -= pref[i - 1][j - 1].second;
                }
            }
            if (j - 1 > 0) {
                pref[i][j].first += pref[i][j - 1].first;
                pref[i][j].second += pref[i][j - 1].second;
            }
        }
    }
    
    int r1, c1, r2, c2, black, white, total;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    while (r1 != 0) {
        black = pref[r2][c2].first;
        if (r1 - 1 > 0) {
            black -= pref[r1 - 1][c2].first;
            if (c2 - 1 > 0) {
                black += pref[r1 - 1][c1 - 1].first;
            }
        }
        if (c1 - 1 > 0) {
            black -= pref[r2][c1 - 1].first;
        }
        white = pref[r2][c2].second;
        if (r1 - 1 > 0) {
            white -= pref[r1 - 1][c2].second;
            if (c2 - 1 > 0) {
                white += pref[r1 - 1][c1 - 1].second;
            }
        }
        if (c1 - 1 > 0) {
            white -= pref[r2][c1 - 1].second;
        }
        if ((r1 & 1) == (c1 & 1)) {
            total = black - white;
        } else {
            total = white - black;
        }
        printf("%d\n", total);
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    }
    
    return 0;
}
