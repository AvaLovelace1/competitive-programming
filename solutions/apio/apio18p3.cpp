/*
 Solution to APIO '18 P3 - Duathlon by Ava Pun
 Key concepts: Tarjan's biconnected components
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, M, N1 = 0;
vi adj[MAX], meta[MAX];
int cnt = 0, NC = 0;
int dfn[MAX], lo[MAX];
bool vis[MAX];
vi comps[MAX];
int nodes[MAX], sz[MAX];
stack<pii> st;
ll ans[MAX], ansV[MAX];

inline void findbcc(int u, int v) {
    if (!st.empty()) {
        NC++;
        vi ss;
        while (!st.empty()) {
            pii e = st.top();
            st.pop();
            ss.pb(e.f), ss.pb(e.s);
            if (e.f == u && e.s == v) {
                break;
            }
        }
        sort(ss.begin(), ss.end());
        ss.erase(unique(ss.begin(), ss.end()), ss.end());
        for (int i : ss) {
            comps[i].pb(NC);
            nodes[NC]++;
        }
        ss.clear();
    }
}

void tarj(int u, int p) {
    dfn[u] = lo[u] = ++cnt;
    vis[u] = 1;
    int ch = 0;
    for (int v : adj[u]) {
        if (!vis[v]) {
            ch++;
            st.push({u, v});
            tarj(v, u);
            lo[u] = min(lo[u], lo[v]);
            if ((p != -1 && lo[v] >= dfn[u]) || (p == -1 && ch > 1)) {
                findbcc(u, v);
            }
        } else if (v != p && dfn[v] < lo[u]) {
            lo[u] = dfn[v];
            st.push({u, v});
        }
    }
}

void dfs(int u, int p) {
    sz[u] = nodes[u];
    vis[u] = 1;
    for (int v : meta[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void solve(int u, int p, int N) {
    if (u <= NC) {
        int n0 = nodes[u] + meta[u].size();
        int n = nodes[u];
        ans[u] += (ll) n * (n0 - 1) * (n0 - 2);
        ans[u] += (ll) n * (n - 1) * (N - n0) * 2;
        ll tot = 0;
        for (int v : meta[u]) {
            int nv = (v == p ? N - sz[u] : sz[v]) - 1;
            ans[u] += (ll) n * 1 * (N - n0 - nv) * 2;
            ans[u] += (ll) n * nv * (N - n0 - nv);
            ansV[v] = (ll) (nv + 1) * (N - (nv + 1) - 1);
            tot += ansV[v];
        }
        for (int v : meta[u]) {
            ans[v] += tot - ansV[v];
        }
    } else {
        for (int v : meta[u]) {
            ans[u] += (ll) nodes[v] * (N - 2);
        }
    }
    for (int v : meta[u]) {
        if (v != p) {
            solve(v, u, N);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int p = 1; p <= N; p++) {
        if (!vis[p]) {
            tarj(p, -1);
            findbcc(-1, -1);
        }
    }
    N1 = NC;
    for (int i = 1; i <= N; i++) {
        if (comps[i].size() > 1) {
            N1++;
            for (int j : comps[i]) {
                meta[j].pb(N1);
                meta[N1].pb(j);
            }
            nodes[N1] = 1;
        }
    }
    for (int i = 1; i <= NC; i++) {
        nodes[i] -= meta[i].size();
    }

    FILL(vis, 0);
    for (int p = 1; p <= N1; p++) {
        if (!vis[p]) {
            dfs(p, -1);
            solve(p, -1, sz[p]);
        }
    }

    printf("%lld\n", accumulate(ans + 1, ans + N1 + 1, 0LL));

    return 0;
}
