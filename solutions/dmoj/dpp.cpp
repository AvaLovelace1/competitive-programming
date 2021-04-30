/*
 * Solution to Independent Set by Ava Pun
 * Key concepts: dynamic programming on trees, combinatorics
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
vector<int> adj[MAX];
long long dpTake[MAX], dpDont[MAX];

void solveDP(int u, int p) {
    dpTake[u] = dpDont[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            solveDP(v, u);
            dpTake[u] *= dpDont[v];
            dpTake[u] %= MOD;
            dpDont[u] *= (dpTake[v] + dpDont[v]) % MOD;
            dpDont[u] %= MOD;
        }
    }
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
    cout << (dpTake[1] + dpDont[1]) % MOD << '\n';
}
