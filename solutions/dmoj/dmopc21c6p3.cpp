/*
 Solution to DMOPC '21 Contest 6 P3 - An Art Problem by Ava Pun
 Key concepts: breadth-first search
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1505;

const pii dirs[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int N, M, K;
int arr[MAX][MAX];
int dist[MAX][MAX];

bool comp(pii a, pii b) {
    return arr[a.f][a.s] < arr[b.f][b.s];
}

bool valid(pii p) {
    return p.f >= 1 && p.f <= N && p.s >= 1 && p.s <= M;
}

void bfs(int k) {

    FILL(dist, -1);
    vii vec;
    REP(i, 1, N) {
        REP(j, 1, M) {
            if (arr[i][j] != 0) {
                dist[i][j] = 0;
                vec.pb({i, j});
            }
        }
    }
    sort(ALL(vec), comp);

    queue<pii> q;
    TRAV(u, vec) q.push(u);

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        if (dist[u.f][u.s] == k) continue;
        TRAV(d, dirs) {
            pii v = {u.f + d.f, u.s + d.s};
            if (dist[v.f][v.s] == -1 && valid(v)) {
                dist[v.f][v.s] = dist[u.f][u.s] + 1;
                arr[v.f][v.s] = arr[u.f][u.s];
                q.push(v);
            }
        }
    }

}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> K;
    REP(i, 1, N) {
        REP(j, 1, M) {
            cin >> arr[i][j];
        }
    }

    bfs(K);

    REP(i, 1, N) {
        REP(j, 1, M) {
            cout << arr[i][j] << " \n"[j == M];
        }
    }

}
