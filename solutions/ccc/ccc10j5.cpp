/*
 Solution to CCC '10 J5 - Knight Hop by Ava Pun
 Key concepts: BFS
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int a1, a2, b1, b2;
int dist[9][9];
bool vis[9][9];

void check(int a, int b, int x, int y, queue<pii> &q) {
    if (x > 0 && x <= 8 && y > 0 && y <= 8 && !vis[x][y]) {
        dist[x][y] = dist[a][b] + 1;
        vis[x][y] = true;
        q.push({x, y});
    }
}

int bfs() {
    queue<pii> q;
    q.push({a1, a2});
    dist[a1][a2] = 0;
    vis[a1][a2] = true;
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        int a = x.first;
        int b = x.second;
        check(a, b, a - 1, b - 2, q);
        check(a, b, a - 2, b - 1, q);
        check(a, b, a + 1, b - 2, q);
        check(a, b, a + 2, b - 1, q);
        check(a, b, a - 1, b + 2, q);
        check(a, b, a - 2, b + 1, q);
        check(a, b, a + 1, b + 2, q);
        check(a, b, a + 2, b + 1, q);
    }
    return dist[b1][b2];
}

int main() {

    scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
    printf("%d", bfs());
    
    return 0;
}
