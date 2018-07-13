/*
 Solution to CCO '15 P4 - Cars on Ice by Ava Pun
 Key concepts: topological sort
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<short int, short int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2005;

int N, M;
char lot[MAX][MAX];
vii adj[MAX][MAX];
int indeg[MAX][MAX];
queue<pii> q;

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &lot[i][j]);
        }
    }
    
    FILL(indeg, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lot[i][j] != '.') {
                indeg[i][j] = 0;
            }
            switch (lot[i][j]) {
                case 'N':
                    for (int k = i - 1; k >= 0; k--) {
                        if (lot[k][j] != '.') {
                            adj[k][j].pb({i, j});
                            indeg[i][j]++;
                        }
                        if (lot[k][j] == 'N') {
                            break;
                        }
                    }
                    break;
                case 'E':
                    for (int k = j + 1; k < M; k++) {
                        if (lot[i][k] != '.') {
                            adj[i][k].pb({i, j});
                            indeg[i][j]++;
                        }
                        if (lot[i][k] == 'E') {
                            break;
                        }
                    }
                    break;
                case 'S':
                    for (int k = i + 1; k < N; k++) {
                        if (lot[k][j] != '.') {
                            adj[k][j].pb({i, j});
                            indeg[i][j]++;
                        }
                        if (lot[k][j] == 'S') {
                            break;
                        }
                    }
                    break;
                case 'W':
                    for (int k = j - 1; k >= 0; k--) {
                        if (lot[i][k] != '.') {
                            adj[i][k].pb({i, j});
                            indeg[i][j]++;
                        }
                        if (lot[i][k] == 'W') {
                            break;
                        }
                    }
                    break;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (indeg[i][j] == 0) {
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        printf("(%d,%d)\n", x.f, x.s);
        for (pii i : adj[x.f][x.s]) {
            indeg[i.f][i.s]--;
            if (indeg[i.f][i.s] == 0) {
                q.push(i);
            }
        }
    }
    
    return 0;
}
