/*
 Solution to COI '06 #3 Sabor by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

const pii dirs[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int B, S;
bool block[2005][2005];
int dist[2005][2005];
ll ans[2];

inline void edge(int k) {
    if (k < S) {
        ll d = S - k;
        ll tmp[2] = {d / 2, (d + 1) / 2};
        if (k & 1) {
            swap(tmp[0], tmp[1]);
        }
        ans[0] += tmp[0], ans[1] += tmp[1];
    }
}

inline void corner(int k) {
    if (k < S - 1) {
        ll d = S - k - 1;
        ll tmp[2] = {((d + 1) / 2)  * ((d + 1) / 2), (d / 2) * (d / 2) + (d / 2)};
        if (k & 1) {
            swap(tmp[0], tmp[1]);
        }
        ans[0] += tmp[0], ans[1] += tmp[1];
    }
}

int main() {
    
    scanf("%d%d", &B, &S);
    int a, b;
    while (B--) {
        scanf("%d%d", &a, &b);
        block[a + 1001][b + 1001] = 1;
    }

    FILL(dist, INF);
    queue<pii> q;
    q.push({1001, 1001});
    dist[1001][1001] = 0;
    
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        for (auto dir : dirs) {
            int r = x.f + dir.f, c = x.s + dir.s;
            if (r >= 0 && r <= 2002 && c >= 0 && c <= 2002 && dist[r][c] == INF && !block[r][c]) {
                dist[r][c] = dist[x.f][x.s] + 1;
                q.push({r, c});
            }
        }
   }

    for (int i = 0; i <= 2002; i++) {
        for (int j = 0; j <= 2002; j++) {
            if (dist[i][j] <= S) {
                ans[dist[i][j] & 1]++;
            }
        }
    }

    for (int i = 0; i <= 2002; i++) {
        edge(dist[i][0]);
        edge(dist[i][2002]);
        edge(dist[0][i]);
        edge(dist[2002][i]);
    }
    corner(dist[0][0]);
    corner(dist[0][2002]);
    corner(dist[2002][0]);
    corner(dist[2002][2002]);

    printf("%lld %lld\n", ans[0], ans[1]);

    return 0;
}
