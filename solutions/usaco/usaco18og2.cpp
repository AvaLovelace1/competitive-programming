/*
 Solution to USACO '18 Open G2 - Milking Order by Ava Pun
 Key concepts: graph theory, topological sort, binary search
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
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int MAXM = 5e4 + 5;

int N, M;
vi adj[MAX];
int indeg[MAX];
vi obs[MAXM];
vi topo;
priority_queue<int, vi, greater<int> > pq;

bool check(int n) {
    
    for (int i = 1; i <= N; i++) {
        adj[i].clear();
        indeg[i] = 0;
    }
    topo.clear();
    while (!pq.empty()) {
        pq.pop();
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < obs[i].size(); j++) {
            adj[obs[i][j - 1]].pb(obs[i][j]);
            indeg[obs[i][j]]++;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) {
            pq.push(i);
        }
    }
    
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topo.pb(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (!indeg[v]) {
                pq.push(v);
            }
        }
    }
    
    return topo.size() == N;
}

int main() {
    
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    int n, x;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &x);
            obs[i].pb(x);
        }
    }
    
    int start = 1, end = M, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (!check(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    
    check(start - 1);
    for (int i = 0; i < topo.size(); i++) {
        printf("%d", topo[i]);
        if (i != topo.size() - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    
    return 0;
}
