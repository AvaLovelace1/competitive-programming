/*
 Solution to DMPG '19 G5 - Hunting the White Whale by Ava Pun
 Key concepts: centroid decomposition, path updates with Euler tour
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, K;
vii adj[MAX];
int sz[MAX];
bool closed[MAX];
map<int, ll> freq, curFreq;
vii nodes;
int cnt;
int in[MAX], out[MAX], tour[2 * MAX];
ll diff[2 * MAX], ans[MAX];

void dfs(int u, int p, int &n) {
    sz[u] = 1;
    n++;
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != p) {
            dfs(v, u, n);
            sz[u] += sz[v];
        }
    }
}

int cent(int u, int p, int n) {
    bool found = (n - sz[u]) <= n / 2;
    int heavyC = -1;
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != p) {
            found &= sz[v] <= n / 2;
            if (heavyC == -1 || sz[v] > sz[heavyC]) {
                heavyC = v;
            }
        }
    }
    return found ? u : cent(heavyC, u, n);
}

inline int cent(int u) {
    int n = 0;
    dfs(u, -1, n);
    int c = cent(u, -1, n);
    closed[c] = 1;
    return c;
}

void dfsEuler(int u, int p) {
    in[u] = ++cnt;
    tour[cnt] = u, diff[cnt] = 0;
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != p) {
            dfsEuler(v, u);
        }
    }
    out[u] = ++cnt;
    tour[cnt] = -u, diff[cnt] = 0;
}

inline void upd(int l, int r, ll x) {
    diff[l] += x, diff[r + 1] -= x;
}

void solve(int u, int p, int sum, bool pass2) {
    if (pass2) {
        nodes.pb({u, sum});
    }
    curFreq[sum]++;
    for (pii e : adj[u]) {
        int v = e.f, w = e.s;
        if (!closed[v] && v != p) {
            solve(v, u, sum + w, pass2);
        }
    }
}

ll solve(int c) {
    ll ret = 0;
    cnt = 0;
    dfsEuler(c, -1);
    freq.clear();
    freq[0] = 1;
    for (pii e : adj[c]) {
        int v = e.f, w = e.s;
        if (!closed[v]) {
            curFreq.clear();
            solve(v, c, w, 0);
            for (auto p : curFreq) {
                ret += freq[K - p.f] * p.s;
            }
            for (auto p : curFreq) {
                freq[p.f] += p.s;
            }
        }
    }
    for (pii e : adj[c]) {
        int v = e.f, w = e.s;
        if (!closed[v]) {
            curFreq.clear();
            nodes.clear();
            solve(v, c, w, 1);
            for (auto &p : nodes) {
                upd(1, in[p.f], freq[K - p.s] - curFreq[K - p.s]);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        diff[i] += diff[i - 1];
        if (abs(tour[i]) != c) {
            if (tour[i] > 0) {
                ans[tour[i]] += diff[i];
            } else {
                ans[-tour[i]] -= diff[i];
            }
        }
    }
    ans[c] += ret;
    for (pii e : adj[c]) {
        int v = e.f;
        if (!closed[v]) {
            ret += solve(cent(v));
        }
    }
    return ret;
}

int main() {
    
    scanf("%d%d", &N, &K);
    int a, b, d;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].pb({b, d});
        adj[b].pb({a, d});
    }

    ll tot = solve(cent(1));
    for (int i = 1; i <= N; i++) {
        ll gcd = __gcd(ans[i], tot);
        if (ans[i] == 0) {
            printf("0 / 1\n");
        } else {
            printf("%lld / %lld\n", ans[i] / gcd, tot / gcd);
        }
    }

    return 0;
}
