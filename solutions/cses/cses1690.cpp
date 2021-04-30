/*
 * Solution to Hamiltonian Flights by Ava Pun
 * Key concepts: bitmask dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int N, M;
vector<int> adj[20];
int dp[20][1 << 20];

// How many routes from u to N using the cities in mask?
int solve(int u, int mask) {
    int &ret = dp[u][mask];
    if (ret != -1) return ret;
    if (u == N - 1) return ret = (mask == 0);
    
    ret = 0;
    for (int v : adj[u]) {
        if (mask & (1 << v)) {
            ret += solve(v, mask & ~(1 << v));
            ret %= MOD;
        }
    }
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, ((1 << N) - 1) & ~1) << '\n';
}
