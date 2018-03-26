/*
 Solution to APIO '12 P1 - Dispatching by Ava Pun
 Key concepts: graph theory, priority queue, heuristic merge
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
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, M;
vi adj[MAX];
int sal[MAX], lvl[MAX], idx[MAX], size[MAX];
ll sum[MAX];
priority_queue<int> pq[MAX];
ll ans = -1;

void solve(int u) {
    
    size[u] = 1;
    int heavyC = -1;
    for (int v : adj[u]) {
        solve(v);
        size[u] += size[v];
        if (heavyC == -1 || size[v] > size[heavyC]) {
            heavyC = v;
        }
    }
    
    if (heavyC == -1) {
        idx[u] = u;
    } else {
        idx[u] = idx[heavyC];
    }
    
    pq[idx[u]].push(sal[u]);
    sum[idx[u]] += sal[u];
    for (int v : adj[u]) {
        if (v != heavyC) {
            while (!pq[idx[v]].empty()) {
                int x = pq[idx[v]].top();
                pq[idx[v]].pop();
                pq[idx[u]].push(x);
                sum[idx[u]] += x;
            }
        }
    }
    
    while (sum[idx[u]] > M) {
        int x = pq[idx[u]].top();
        pq[idx[u]].pop();
        sum[idx[u]] -= x;
    }
    
    ans = max(ans, (ll) lvl[u] * (ll) pq[idx[u]].size());
}

int main() {
    
    scanf("%d%d", &N, &M);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &n, &sal[i], &lvl[i]);
        adj[n].pb(i);
    }
    solve(1);
    printf("%lld\n", ans);
    
    return 0;
}
