/*
 Solution to Drazil and Tiles by Ava Pun
 Key concepts: greedy algorithms, graph theory
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
const int MAX = 2002;

const pii dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M;
char arr[MAX][MAX];
vii adj[MAX][MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int NClear = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == '.') {
                NClear++;
                for (auto dir : dirs) {
                    int i1 = i + dir.f, j1 = j + dir.s;
                    if (arr[i1][j1] == '.') {
                        adj[i][j].pb({i1, j1});
                    }
                }
            }
        }
    }

    queue<pii> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == '.' && adj[i][j].size() <= 1) {
                q.push({i, j});
            }
        }
    }
    int covered = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        int i = cur.f, j = cur.s;
        if (arr[i][j] == '.') {
            if (adj[i][j].size() < 1) {
                break;
            } else {
                pii nxt = adj[i][j][0];
                int i1 = nxt.f, j1 = nxt.s;
                for (auto p : adj[i1][j1]) {
                    adj[p.f][p.s].erase(find(adj[p.f][p.s].begin(), adj[p.f][p.s].end(), nxt));
                    if (adj[p.f][p.s].size() <= 1) {
                        q.push({p.f, p.s});
                    }
                }
                if (i1 == i + 1) {
                    arr[i][j] = '^', arr[i1][j1] = 'v';
                } else if (i1 == i - 1) {
                    arr[i][j] = 'v', arr[i1][j1] = '^';
                } else if (j1 == j + 1) {
                    arr[i][j] = '<', arr[i1][j1] = '>';
                } else if (j1 == j - 1) {
                    arr[i][j] = '>', arr[i1][j1] = '<';
                }
                covered += 2;
            }
        }
    }
    if (covered != NClear) {
        printf("Not unique\n");
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
