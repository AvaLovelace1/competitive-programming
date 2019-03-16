/*
 Solution to WC17 #3 - Relevant Results by Ava Pun
 Key concepts: Tarjan's strongly connected components, convex hull of functions
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, bool> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 4e5 + 5;

int N, Q;
vi adj[MAX];
int rel[MAX], cost[MAX];

int low[MAX], dfn[MAX];
bool vis[MAX];
stack<int> st;
int cnt = 1;
int compCnt = 0;
vi comps[MAX];
int comp[MAX], indeg[MAX];

pii quers[MAX];
vi q;
double over[MAX];
vector<pair<ll, ll>> events[MAX];
ll ans[MAX];

inline void findscc(int u) {
    if (st.empty()) {
        return;
    }
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        dfn[v] = INF;
        comps[compCnt].pb(v);
        comp[v] = compCnt;
        if (v == u) {
            break;
        }
    }
    compCnt++;
}

void tarjscc(int u) {
    dfn[u] = low[u] = cnt;
    vis[u] = true;
    cnt++;
    st.push(u);
    for (int v : adj[u]) {
        if (!vis[v]) {
            tarjscc(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        findscc(u);
    }
}

inline bool costComp(int a, int b) {
    if (cost[a] == cost[b]) {
        return rel[a] < rel[b];
    }
    return cost[a] > cost[b];
}

inline double overtake(int a, int b) {
    if (cost[a] == cost[b]) {
        return -INFL;
    }
    return ((double) rel[a] * cost[a] - (double) rel[b] * cost[b]) / ((double) cost[a] - cost[b]);
}

int main() {
    
    scanf("%d", &N);
    int k, n;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &rel[i], &cost[i], &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d", &n);
            adj[i].pb(n);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            tarjscc(i);
            findscc(-1);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            if (comp[i] != comp[j]) {
                indeg[comp[j]]++;
            }
        }
    }
    
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &quers[i].f);
        quers[i].s = i;
    }
    sort(quers + 1, quers + Q + 1);
    
    ll sumCost = 0, relCost = 0;
    for (int u = 0; u < compCnt; u++) {
        if (indeg[u] == 0) {
            sort(comps[u].begin(), comps[u].end(), costComp);
            q.clear();
            for (int v : comps[u]) {
                while (q.size() > 1 && over[q.size() - 1] >= overtake(q[q.size() - 1], v)) {
                    q.pop_back();
                }
                if (!q.empty()) {
                    over[q.size()] = overtake(q[q.size() - 1], v);
                }
                q.pb(v);
            }
            for (int i = 0; i < q.size(); i++) {
                pii p = {ceil(min((double) INF, over[i])), -1};
                int idxOver = (int) (lower_bound(quers + 1, quers + Q + 1, p) - quers);
                p = {ceil(min((double) INF, over[i + 1])), -1};
                int idxDisapp = (int) (lower_bound(quers + 1, quers + Q + 1, p) - quers);
                p = {rel[q[i]], -1};
                int idxStart = (int) (lower_bound(quers + 1, quers + Q + 1, p) - quers);
                if (i == q.size() - 1) {
                    idxDisapp = Q + 1;
                }
                if (i == 0) {
                    idxOver = 1;
                }
                int idxApp = max(idxOver, idxStart);
                // will appear once it takes over *and* x >= rel
                events[min(idxApp, idxDisapp)].pb({cost[q[i]], (ll) rel[q[i]] * cost[q[i]]});
                // will disappear once it is overtaken
                events[idxDisapp].pb({-cost[q[i]], - (ll) rel[q[i]] * cost[q[i]]});
            }
        }
    }
    
    for (int i = 1; i <= Q; i++) {
        for (auto p : events[i]) {
            sumCost += p.f, relCost += p.s;
        }
        ans[quers[i].s] = quers[i].f * sumCost - relCost;
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
