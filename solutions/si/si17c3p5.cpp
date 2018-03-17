/*
 Solution to Summer Institute '17 Contest 3 P5 - Balanced Cycles by Ava Pun
 Key concepts: graph theory, centroid decomposition
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
const int MAX = 1e5 + 5;

int N;
vii adj[MAX];
int size[MAX];
bool closed[MAX];
unordered_map<int, ll> m, arr;
vi cents;

void dfs(int u, int prev, int &n) {
    size[u] = 1;
    n++;
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != prev) {
            dfs(v, u, n);
            size[u] += size[v];
        }
    }
}

int centroid(int u, int prev, int n) {
    bool found = true;
    int heavyC = -1;
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != prev) {
            if (size[v] > n / 2) {
                found = false;
            }
            if (heavyC == -1 || size[v] > size[heavyC]) {
                heavyC = v;
            }
        }
    }
    if (found && n - size[u] <= n / 2) {
        return u;
    } else {
        return centroid(heavyC, u, n);
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
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != prev) {
            m[sum + e.s]++;
            solve(v, u, sum + e.s);
        }
    }
}

ll solve(int cent) {
    ll ans = 0;
    cents.clear();
    arr.clear();
    for (pii e : adj[cent]) {
        m.clear();
        int v = e.f;
        if (!closed[v]) {
            m[e.s]++;
            solve(v, cent, e.s);
            for (auto p : m) {
                int i = p.f;
                if (i == 1 || i == -1) {
                    ans += p.s;
                }
                ans += p.s * (arr[-i + 1] + arr[-i - 1]);
            }
            for (auto p : m) {
                arr[p.f] += p.s;
            }
            cents.pb(centroid(v));
        }
    }
    vi tmp = cents;
    for (int i : tmp) {
        ans += solve(i);
    }
    return ans;
}

int main() {
    
    scanf("%d", &N);
    int a, b;
    char c;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d %c", &a, &b, &c);
        int col = c == 'r' ? 1 : -1;
        adj[a].pb({b, col});
        adj[b].pb({a, col});
    }
    
    printf("%lld\n", solve(centroid(1)) - (N - 1));
    
    return 0;
}
