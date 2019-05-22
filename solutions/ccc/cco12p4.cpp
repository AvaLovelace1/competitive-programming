/*
 Solution to CCO '12 P4 - Editor Distance by Ava Pun
 Key concepts: BFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int N;
int arr[MAX];
pii S, T;
int dist[MAX][85];

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d%d", &S.f, &S.s);
    scanf("%d%d", &T.f, &T.s);

    FILL(dist, INF);
    queue<pii> q;
    q.push(S);
    dist[S.f][S.s] = 0;

    while (!q.empty()) {
        int r = q.front().f, c = q.front().s;
        q.pop();
        vii nxt;
        if (c == arr[r]) {
            if (r != N) {
                nxt.pb({r + 1, 1});
            }
        } else {
            nxt.pb({r, c + 1});
        }
        if (c == 1) {
            if (r != 1) {
                nxt.pb({r - 1, arr[r - 1]});
            }
        } else {
            nxt.pb({r, c - 1});
        }
        if (r != 1) {
            nxt.pb({r - 1, min(arr[r - 1], c)});
        }
        if (r != N) {
            nxt.pb({r + 1, min(arr[r + 1], c)});
        }
        for (pii p : nxt) {
            if (dist[p.f][p.s] == INF) {
                dist[p.f][p.s] = dist[r][c] + 1;
                q.push(p);
            }
        }
        nxt.clear();
    }
    printf("%d\n", dist[T.f][T.s]);

    return 0;
}
