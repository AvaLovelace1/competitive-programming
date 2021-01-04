/*
 * Solution to USACO '20 December S1 - Cowntagion by Ava Pun
 * Key concepts: graph theory, trees
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;
const double EPS = 1e-9;

int N;
vi adj[MAX];
bool vis[MAX];

int solve(int u) {
    vis[u] = 1;

    int ans = 0;
    int nChildren = 0;
    for (int v : adj[u]) {
        if (!vis[v]) {
            ans += solve(v);
            ++nChildren;
        }
    }

    ans += (int) ceil(log2(nChildren + 1));
    ans += nChildren;
    return ans;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int a, b;
    for (int i = 1; i <= N - 1; ++i) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout << solve(1) << '\n';

}

