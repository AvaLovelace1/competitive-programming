/*
 Solution to CCO '16 P4 - O Canada by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int N, G;
bool grid[11][11];
unordered_map<int, int> mp;

int main() {

    scanf("%d%d", &N, &G);

    char c;
    for (int t = 1; t <= G; t++) {

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf(" %c", &c);
                grid[i][j] = c == 'R';
            }
        }

        for (int i = 1; i <= N - 1; i++) {
            for (int j = 1; j <= N - 1; j++) {
                if (grid[i][j]) {
                    for (int k = 0; k <= 1; k++) {
                        for (int l = 0; l <= 1; l++) {
                            grid[i + k][j + l] = !grid[i + k][j + l];
                        }
                    }
                }
            }
        }

        int pos = 0, m = 0;
        for (int i = 1; i <= N - 1; i++) {
            m |= (grid[i][N] << pos);
            pos++;
        }
        for (int i = 1; i <= N; i++) {
            m |= (grid[N][i] << pos);
            pos++;
        }
        mp[m]++;

    }

    int ans = 0;
    for (auto p : mp) {
        ans += p.s * (p.s - 1) / 2;
    }
    printf("%d\n", ans);

    return 0;
}
