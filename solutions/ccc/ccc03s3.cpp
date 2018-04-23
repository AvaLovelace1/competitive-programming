/*
 Solution to CCC '03 S3 - Floor Plan by Ava Pun
 Key concepts: graph theory, DFS
 */

#include <bits/stdc++.h>

using namespace std;

int n, r, c;
char grid[27][27];

int dfs(int i, int j) {
    if (grid[i][j] == '.') {
        grid[i][j] = 'I';
        return 1 + dfs(i + 1, j) + dfs(i, j + 1) + dfs(i - 1, j) + dfs(i, j - 1);
    } else {
        return 0;
    }
}

int main() {

    scanf("%d%d%d", &n, &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%*c");
        for (int j = 1; j <= c; j++) {
            scanf("%c", &grid[i][j]);
        }
    }
    
    vector<int> sizes;
    int s;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            s = dfs(i, j);
            if (s != 0) {
                sizes.push_back(s);
            }
        }
    }
    
    sort(sizes.begin(), sizes.end(), greater<int>());
    int count = 0;
    for (int i : sizes) {
        if (i <= n) {
            count++;
            n -= i;
        } else {
            break;
        }
    }
    printf("%d room%s, %d square metre(s) left over", count, count == 1 ? "" : "s", n);
    
    return 0;
    
}
