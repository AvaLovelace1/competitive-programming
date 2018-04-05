/*
 Solution to TLE '15 P6 - Rock, Paper, Scissors by Ava Pun
 Key concepts: strongly connected components, Tarjan's, dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5005, MAXE = 10005;

int N, M, Q;
vector<int> adj[MAX];
unordered_set<int> meta[MAX];
int dfn[MAX], low[MAX], size[MAX], comp[MAX];
bool vis[MAX];
stack<int> st;
int cnt = 0, compCnt = 0;
int dp[MAX][MAX];

void findscc(int u) {
    if (st.empty()) {
        return;
    }
    compCnt++;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        dfn[v] = INF;
        comp[v] = compCnt;
        size[compCnt]++;
        if (v == u) {
            break;
        }
    }
}

void tarj(int u) {
    
    dfn[u] = low[u] = cnt;
    vis[u] = true;
    cnt++;
    st.push(u);
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            tarj(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
    if (low[u] == dfn[u]) {
        findscc(u);
    }
    
}

int solve(int u, int v) {
    if (dp[u][v] == -2) {
        if (u == v) {
            dp[u][v] = size[u];
        } else {
            dp[u][v] = -1;
            for (int i : meta[u]) {
                if (solve(i, v) != -1) {
                    dp[u][v] = max(dp[u][v], solve(i, v) + size[u]);
                }
            }
        }
    }
    return dp[u][v];
}

int main() {
    
    scanf("%d%d%d", &N, &M, &Q);
    int a, b;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            tarj(i);
            findscc(-1);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            if (comp[i] != comp[j]) {
                meta[comp[i]].insert(comp[j]);
            }
        }
    }
    
    for (int i = 1; i <= compCnt; i++) {
        for (int j = 1; j <= compCnt; j++) {
            dp[i][j] = -2;
        }
    }
    for (int i = 1; i <= compCnt; i++) {
        for (int j = 1; j <= compCnt; j++) {
            solve(i, j);
        }
    }
    
    while (Q--) {
        scanf("%d%d", &a, &b);
        if (comp[a] == comp[b]) {
            printf("Indeterminate\n");
        } else {
            int a0 = dp[comp[a]][comp[b]];
            int b0 = dp[comp[b]][comp[a]];
            if (a0 == -1 && b0 == -1) {
                printf("Indeterminate\n");
            } else if (b0 == -1) {
                printf("%d %d\n", a, dp[comp[a]][comp[b]] - size[comp[a]] - size[comp[b]]);
            } else {
                printf("%d %d\n", b, dp[comp[b]][comp[a]] - size[comp[a]] - size[comp[b]]);
            }
        }
    }
    
    return 0;
    
}
