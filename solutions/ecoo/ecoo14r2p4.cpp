/*
 Solution to ECOO '14 R2 P4 - What Lies Ahead by Ava Pun
 Key concepts: graph theory, DFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2 * 250 + 5;

int S;
char grid[6][6];
bool vis[6][6][4];

bool clear(int i, int j) {
    return i >= 0 && i < 6 && j >= 0 && j < 6 && grid[i][j] != '.';
}

void dfs(int i0, int j0, int dir);

void move(char c, int i, int j, int dir) {
    if (c == 'U') {
        dfs(i - 1, j, dir);
    } else if (c == 'D') {
        dfs(i + 1, j, dir);
    } else if (c == 'L') {
        dfs(i, j - 1, dir);
    } else if (c == 'R') {
        dfs(i, j + 1, dir);
    } else if (c == 'C') {
        dfs(i, j, (dir + 1) % 4);
    } else if (c == 'B') {
        dfs(i, j, (dir - 1 + 4) % 4);
    }
}

void dfs(int i0, int j0, int dir) {
    
    if (!clear(i0, j0) || vis[i0][j0][dir]) {
        return;
    }
    vis[i0][j0][dir] = true;
    if (grid[i0][j0] == 'T') {
        return;
    }
    
    int i = i0, j = j0;
    
    if (grid[i][j] == 'S') {
        if (dir == 0) {
            i--;
            while (clear(i, j)) {
                if (grid[i][j] == 'U') {
                    move(grid[i][j], i0, j0, dir);
                }
                i--;
            }
        }
    } else {
        if (dir == 0) {
            i--;
            while (clear(i, j)) {
                move(grid[i][j], i0, j0, dir);
                i--;
            }
        } else if (dir == 1) {
            j++;
            while (clear(i, j)) {
                move(grid[i][j], i0, j0, dir);
                j++;
            }
        } else if (dir == 2) {
            i++;
            while (clear(i, j)) {
                move(grid[i][j], i0, j0, dir);
                i++;
            }
        } else if (dir == 3) {
            j--;
            while (clear(i, j)) {
                move(grid[i][j], i0, j0, dir);
                j--;
            }
        }
    }
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        FILL(vis, 0);
        for (int i = 0; i < 6; i++) {
            scanf("%s", grid[i]);
        }
        for (int i = 0; i < 6; i++) {
            if (grid[5][i] == 'S') {
                S = i;
                break;
            }
        }
        
        dfs(5, S, 0);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (grid[i][j] == 'T') {
                    bool found = false;
                    for (int k = 0; k < 4 && !found; k++) {
                        if (vis[i][j][k]) {
                            found = true;
                        }
                    }
                    printf("%c", found ? 'T' : 'F');
                }
            }
        }
        printf("\n");
        
    }
    
    return 0;
}
