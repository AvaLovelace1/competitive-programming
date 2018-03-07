/*
 Solution to Mock CCC14J5 - Spacetime Surfer by Ava Pun
 Key concepts: graph theory, BFS
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int INF = 0x3F3F3F3F;
int R, C, T;
pii A, B;
char arr[101][101][10];
bool vis[101][101][10];
int dist[101][101][10];
queue<piii> q;

void process(int i0, int j0, int k0, int i, int j, int k) {
    if (i < 0 || i >= R || j < 0 || j >= C || k < 0 || k >= T) {
        return;
    }
    if (arr[i][j][k] != 'X' && !vis[i][j][k]) {
        vis[i][j][k] = true;
        dist[i][j][k] = dist[i0][j0][k0] + 1;
        q.push({{i, j}, k});
    }
}

int main() {
    
    scanf("%d%d%d", &R, &C, &T);
    for (int k = 0; k < T; k++) {
        for (int i = 0; i < R; i++) {
            scanf("%*c");
            for (int j = 0; j < C; j++) {
                scanf("%c", &arr[i][j][k]);
                if (arr[i][j][k] == 'A') {
                    A = {i, j};
                } else if (arr[i][j][k] == 'B') {
                    B = {i, j};
                }
            }
        }
    }
    
    memset(dist, INF, sizeof(dist));
    vis[A.first][A.second][0] = true;
    dist[A.first][A.second][0] = 0;
    q.push({A, 0});
    
    while (!q.empty()) {
        piii x = q.front();
        q.pop();
        int a = x.first.first;
        int b = x.first.second;
        int c = x.second;
        process(a, b, c, a + 1, b, c);
        process(a, b, c, a - 1, b, c);
        process(a, b, c, a, b + 1, c);
        process(a, b, c, a, b - 1, c);
        for (int i = 0; i < T; i++) {
            if (i != c) {
                process(a, b, c, a, b, i);
            }
        }
    }
    
    if (dist[B.first][B.second][0] == INF) {
        printf("-1");
    } else {
        printf("%d", dist[B.first][B.second][0]);
    }
    
    return 0;
    
}
