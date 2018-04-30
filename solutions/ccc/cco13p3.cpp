/*
 Solution to CCO '13 P3 - LHC by Ava Pun
 Key concepts: graph theory, diameter of a tree, centroid decomposition
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
const int MOD = 1e9 + 7;
const int MAX = 4e5 + 5;

int N;
vi adj[MAX];
int size[MAX], dist[MAX];
bool closed[MAX];
unordered_map<int, ll> freq, currFreq;

void dfs(int u, int prev, int &n) {
    size[u] = 1;
    n++;
    for (int v : adj[u]) {
        if (v != prev && !closed[v]) {
            dfs(v, u, n);
            size[u] += size[v];
        }
    }
}

int centroid(int u, int prev, int n) {
    bool found = true;
    int heavyC = -1;
    for (int v : adj[u]) {
        if (v != prev && !closed[v]) {
            if (heavyC == -1 || size[v] > size[heavyC]) {
                heavyC = v;
            }
            if (size[v] > n / 2) {
                found = false;
            }
        }
    }
    if (!found || n - size[u] > n / 2) {
        return centroid(heavyC, u, n);
    } else {
        return u;
    }
}

int centroid(int u) {
    int n = 0;
    dfs(u, -1, n);
    int cent = centroid(u, -1, n);
    closed[cent] = true;
    return cent;
}

void solve(int u, int prev, int sum) {
    currFreq[sum]++;
    for (int v : adj[u]) {
        if (v != prev && !closed[v]) {
            solve(v, u, sum + 1);
        }
    }
}

ll solve(int cent, int k) {
    freq.clear();
    freq[0] = 1;
    ll ans = 0;
    for (int v : adj[cent]) {
        if (!closed[v]) {
            currFreq.clear();
            solve(v, cent, 1);
            for (auto p : currFreq) {
                ans += p.s * freq[k - p.f];
            }
            for (auto p : currFreq) {
                freq[p.f] += p.s;
            }
        }
    }
    for (int v : adj[cent]) {
        if (!closed[v]) {
            ans += solve(centroid(v), k);
        }
    }
    return ans;
}

ll solve(int k) {
    FILL(closed, 0);
    return solve(centroid(1), k);
}

void dfs(int u, int prev) {
    for (int v : adj[u]) {
        if (v != prev) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    
    scanf("%d", &N);
    int a, b;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dist[1] = 0;
    dfs(1, -1);
    int n = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > dist[n]) {
            n = i;
        }
    }
    dist[n] = 0;
    dfs(n, -1);
    int d = *max_element(dist + 1, dist + N + 1);
    printf("%d %lld\n", d + 1, solve(d));
    
    return 0;
}
