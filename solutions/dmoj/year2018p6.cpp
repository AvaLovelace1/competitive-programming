/*
 Solution to Old Christmas Lights II by Ava Pun
 Key concepts: Mo's algorithm on tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;
const int MAXL = 17;

int N, Q;
int arr[MAX];
vi adj[MAX];
int depth[MAX], dp[MAX][MAXL], tin[MAX], tout[MAX], tour[2 * MAX];
int cnt = 0;
piii quers[MAX];
int ans[MAX];
int BLOCK, LOG;
bool used[MAX];
multiset<int> ms1, ms2;

void dfs(int u, int prev) {
    cnt++;
    tour[cnt] = u;
    tin[u] = cnt;
    for (int v : adj[u]) {
        if (v != prev) {
            dp[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    cnt++;
    tour[cnt] = u;
    tout[u] = cnt;
}

inline bool ancest(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

inline int lca(int u, int v) {
    if (ancest(u, v)) {
        return u;
    } else if (ancest(v, u)) {
        return v;
    } else {
        for (int i = LOG; i >= 0; i--) {
            if (dp[v][i] != -1 && !ancest(dp[v][i], u)) {
                v = dp[v][i];
            }
        }
        return dp[v][0];
    }
}

inline bool comp(piii a, piii b) {
    if (a.f.f / BLOCK == b.f.f / BLOCK) {
        return a.f.s < b.f.s;
    } else {
        return a < b;
    }
}

inline void rem(int n);

inline void add(int u) {
    if (used[u]) {
        rem(u);
        return;
    }
    int n = arr[u];
    auto it = ms1.lower_bound(n);
    auto down = it;
    if (it != ms1.begin()) {
        down--;
        ms2.insert(n - *down);
    }
    if (it != ms1.end()) {
        ms2.insert(*it - n);
    }
    if (it != ms1.begin() && it != ms1.end()) {
        ms2.erase(ms2.find(*it - *down));
    }
    ms1.insert(n);
    used[u] = 1;
}

inline void rem(int u) {
    if (!used[u]) {
        add(u);
        return;
    }
    int n = arr[u];
    auto it = ms1.lower_bound(n);
    auto up = it, down = it;
    if (it != ms1.begin()) {
        down--;
        ms2.erase(ms2.find(*it - *down));
    }
    if (it != --ms1.end()) {
        up++;
        ms2.erase(ms2.find(*up - *it));
    }
    if (it != ms1.begin() && it != --ms1.end()) {
        ms2.insert(*up - *down);
    }
    ms1.erase(it);
    used[u] = 0;
}

int main() {
    
    scanf("%d%d", &N, &Q);
    BLOCK = 500;
    LOG = ceil(log2(N));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    int a, b, c;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    FILL(dp, -1);
    dfs(1, -1);
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i <= N; i++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d", &a, &b);
        if (tin[b] < tin[a]) {
            swap(a, b);
        }
        c = lca(a, b);
        if (c == a) {
            quers[i] = {{tin[c], tin[b]}, {c, i}};
        } else {
            quers[i] = {{tout[a], tin[b]}, {c, i}};
        }
    }
    sort(quers + 1, quers + Q + 1, comp);

    int idxl = 1, idxr = 1;
    for (int i = 1; i <= Q; i++) {
        int l = quers[i].f.f, r = quers[i].f.s, anc = quers[i].s.f, idx = quers[i].s.s;
        while (idxl < l) {
            rem(tour[idxl]);
            idxl++;
        }
        while (idxl > l) {
            idxl--;
            add(tour[idxl]);
        }
        while (idxr < r + 1) {
            add(tour[idxr]);
            idxr++;
        }
        while (idxr > r + 1) {
            idxr--;
            rem(tour[idxr]);
        }
        if (!used[anc]) {
            add(anc);
            ans[idx] = *ms2.begin();
            rem(anc);
        } else {
            ans[idx] = *ms2.begin();
        }
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
