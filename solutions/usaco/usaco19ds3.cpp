/*
 * Solution to USACO '19 December S3 - Milk Visits by Ava Pun
 * Key concepts: graph theory, DFS, trees
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5+2;

int N, M;
bool arr[MAX];
vi adj[MAX];
bool vis[2][MAX];
int comp[2][MAX];
int compCnt = 0;

void dfs(int u, bool t) {
    vis[t][u] = true;
    comp[t][u] = compCnt;
    for (int v : adj[u]) {
        if (arr[v] == t && !vis[t][v]) {
            dfs(v, t);
        }
    }
}

void solve(bool t) {
    compCnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (arr[i] == t && !vis[t][i]) {
            ++compCnt;
            dfs(i, t);
        }
    }
}

int main() {

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    char c;
    for (int i = 1; i <= N; ++i) {
        cin >> c;
        arr[i] = c == 'H';
    }
    for (int i = 1; i <= N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    solve(0);
    solve(1);

    
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b >> c;
        bool t = c != 'H';
        if (comp[t][a] == comp[t][b] && comp[t][a] != 0) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout << '\n';

}
