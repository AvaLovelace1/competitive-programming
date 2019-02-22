/*
 Solution to IOI '09 P7 - Regions by Ava Pun
 Key concepts: trees, DFS, Euler tour, square root tricks
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

int N, R, Q;
int BLOCK_SIZE;
int arr[MAX];
vi ppl[25005];
int mp[25005], preComp[450][25005];
vi adj[MAX];
int in[MAX], out[MAX];
vi tour[25005];
int dfsCnt = 0;

void dfs(int u, int r, int n) {
    for (int v : adj[u]) {
        preComp[mp[r]][arr[v]] += n;
        dfs(v, r, n + (arr[v] == r));
    }
}

void dfsTour(int u) {
    in[u] = ++dfsCnt;
    tour[arr[u]].pb(in[u]);
    for (int v : adj[u]) {
        dfsTour(v);
    }
    out[u] = dfsCnt;
}

inline int solve(int r1, int r2) {
    int ans = 0;
    for (int i : ppl[r1]) {
        ans += upper_bound(tour[r2].begin(), tour[r2].end(), out[i])
            - lower_bound(tour[r2].begin(), tour[r2].end(), in[i]);
    }
    return ans;
}

int main() {

    scanf("%d%d%d", &N, &R, &Q);
    BLOCK_SIZE = sqrt(N);
    int p;
    for (int i = 1; i <= N; i++) {
        if (i != 1) {
            scanf("%d", &p);
            adj[p].pb(i);
        }
        scanf("%d", &arr[i]);
        ppl[arr[i]].pb(i);
    }
    
    int idx = 0;
    for (int i = 1; i <= R; i++) {
        if (ppl[i].size() >= BLOCK_SIZE) {
            mp[i] = ++idx;
            dfs(1, i, arr[1] == i);
        }
    }
    dfsTour(1);
    
    int r1, r2;
    while (Q--) {
        scanf("%d%d", &r1, &r2);
        if (ppl[r1].size() >= BLOCK_SIZE) {
            printf("%d\n", preComp[mp[r1]][r2]);
            fflush(stdout);
        } else {
            printf("%d\n", solve(r1, r2));
            fflush(stdout);
        }
    }

    return 0;
}
