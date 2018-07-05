/*
 Solution to DMOPC '13 Contest 1 P4 - AFK by Ava Pun
 Key concepts: BFS
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
const int MAX = 5e4 + 5;

const pii moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int T, N, M;
char arr[55][55];
int dist[55][55];

int main() {
    
    scanf("%d", &T);
    
    while (T--) {
        
        FILL(arr, 'X');
        scanf("%d%d", &M, &N);
        pii S = {0, 0}, T = {0, 0};
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf(" %c", &arr[i][j]);
                if (arr[i][j] == 'C') {
                    S = {i, j};
                } else if (arr[i][j] == 'W') {
                    T = {i, j};
                }
            }
        }
        
        FILL(dist, INF);
        queue<pii> q;
        q.push(S);
        dist[S.f][S.s] = 0;
        while (!q.empty()) {
            pii p = q.front();
            q.pop();
            int r0 = p.f, c0 = p.s;
            for (pii m : moves) {
                int r = r0 + m.f, c = c0 + m.s;
                if (arr[r][c] != 'X' && dist[r][c] == INF) {
                    dist[r][c] = dist[r0][c0] + 1;
                    q.push({r, c});
                }
            }
        }
        
        if (dist[T.f][T.s] >= 60) {
            printf("#notworth\n");
        } else {
            printf("%d\n", dist[T.f][T.s]);
        }
        
    }
    
    return 0;
}
