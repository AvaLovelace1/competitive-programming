/*
 * Solution to Moving to the Capital by Ava Pun
 * Key concepts: graph theory, BFS, DFS, dynamic programming
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
const int MAX = 2e5 + 5;

int T, N, M;
vi adj[MAX];
int dist[MAX];
int ans[MAX];

void bfs() {
    REP(i, 1, N) {
        dist[i] = -1;
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int dfs(int u) {
    if (ans[u] != -1) return ans[u];
    ans[u] = dist[u];
    for (int v : adj[u]) {
        if (dist[v] > dist[u]) {
            ans[u] = min(ans[u], dfs(v));
        } else {
            ans[u] = min(ans[u], dist[v]);
        }
    }
    return ans[u];
}

void dfs() {
    REP(i, 1, N) {
        ans[i] = -1;
    }
    REP(i, 1, N) {
        dfs(i);
    }
}

void solve() {
    bfs();
    dfs();
    REP(i, 1, N) {
        cout << ans[i] << " \n"[i == N];
    }
}

void init() {
    cin >> N >> M;
    REP(i, 1, N) {
        adj[i].clear();
    }
    REP(i, 1, M) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> T;
    REP(t, 1, T) {
        init();
        solve();
    }

}

