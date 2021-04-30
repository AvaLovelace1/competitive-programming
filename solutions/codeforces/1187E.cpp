/*
 * Solution to Tree Painting by Ava Pun
 * Key concepts: dynamic programming on trees, tree rerooting
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int N;
vector<int> adj[MAX];
int sz[MAX];
long long dp[MAX];

void solveDP(int u, int p) {
    sz[u] = 0;
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v != p) {
            solveDP(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v];
        }
    }
    ++sz[u];
    dp[u] += sz[u];
}

long long findBest(int u, int p) {
    long long ret = dp[u];
    for (int v : adj[u]) {
        if (v != p) {
            int origSzU = sz[u], origSzV = sz[v];
            long long origDPU = dp[u], origDPV = dp[v];
            dp[u] -= sz[v] + dp[v]; 
            dp[v] += dp[u] + N - sz[v];
            sz[u] -= sz[v];
            sz[v] = N;

            ret = max(ret, findBest(v, u));

            sz[u] = origSzU, sz[v] = origSzV;
            dp[u] = origDPU, dp[v] = origDPV;
        }
    }
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solveDP(1, -1);
    cout << findBest(1, -1) << '\n';

}
