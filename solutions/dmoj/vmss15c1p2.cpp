/*
 Solution to VMSS '15 #2 - Tomb Robbing by Ava Pun
 Key concepts: graph theory, DFS
 */

#include <bits/stdc++.h>

using namespace std;

int r, c;
char grid[102][102];

bool dfs(int i, int j) {
    if (grid[i][j] == '.') {
        grid[i][j] = 'X';
        dfs(i, j + 1);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i - 1, j);
        return 1;
    } else {
        return 0;
    }
}

int main() {

    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%*c");
        for (int j = 1; j <= c; j++) {
            scanf("%c", &grid[i][j]);
        }
    }
    
    int sum = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            sum += dfs(i, j);
        }
    }
    
    printf("%d", sum);
    
    return 0;
    
}
