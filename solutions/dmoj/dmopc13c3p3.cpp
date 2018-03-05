/*
 Solution to DMOPC '13 Contest 3 P3 - Crossing Field by Ava Pun
 Key concepts: DFS
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1505;

int N, H;
int elev[MAX][MAX];
bool vis[MAX][MAX];

void check(int x, int y, int a, int b, stack<pii> &s) {
    if (a > 0 && a <= N && b > 0 && b <= N && !vis[a][b]) {
        if (abs(elev[x][y] - elev[a][b]) <= H) {
            s.push({a, b});
            vis[a][b] = true;
        }
    }
}

bool dfs() {
    stack<pii> s;
    s.push({1, 1});
    vis[1][1] = true;
    while (!s.empty()) {
        pii x = s.top();
        s.pop();
        int a = x.first;
        int b = x.second;
        check(a, b, a - 1, b, s);
        check(a, b, a + 1, b, s);
        check(a, b, a, b - 1, s);
        check(a, b, a, b + 1, s);
    }
    return vis[N][N];
}

int main() {
    
    scanf("%d%d", &N, &H);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &elev[i][j]);
        }
    }
    
    bool b = dfs();
    if (b) {
        printf("yes");
    } else {
        printf("no");
    }
    
    return 0;
}
