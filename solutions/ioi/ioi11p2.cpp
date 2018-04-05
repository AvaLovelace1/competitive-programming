/*
 Solution to IOI '11 P2 - Race by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

vii adj[MAX];
int size[MAX];
bool closed[MAX];
int best[(int) 1e6 + 5], bestTmp[(int) 1e6 + 5];
vi added, addedTmp;

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

void add(int tot, int totE, int arr[], vi &added, int K){
    if (tot > K) {
        return;
    }
    arr[tot] = min(arr[tot], totE);
    added.pb(tot);
}

void clear(int arr[], vi &added) {
    for (int i : added) {
        arr[i] = INF;
    }
    added.clear();
    arr[0] = 0;
}

void solve(int u, int prev, int tot, int totE, int K) {
    for (pii e : adj[u]) {
        int v = e.f;
        if (!closed[v] && v != prev) {
            add(tot + e.s, totE + 1, bestTmp, addedTmp, K);
            solve(v, u, tot + e.s, totE + 1, K);
        }
    }
}

int solve(int cent, int K) {
    
    clear(best, added);
    int ans = INF;
    
    for (pii e : adj[cent]) {
        int v = e.f;
        if (!closed[v]) {
            clear(bestTmp, addedTmp);
            add(e.s, 1, bestTmp, addedTmp, K);
            solve(v, cent, e.s, 1, K);
            for (int i : addedTmp) {
                if (i <= K && best[K - i] != INF) {
                    ans = min(ans, bestTmp[i] + best[K - i]);
                }
            }
            for (int i : addedTmp) {
                add(i, bestTmp[i], best, added, K);
            }
        }
    }
    
    for (pii e : adj[cent]) {
        int v = e.f;
        if (!closed[v]) {
            ans = min(ans, solve(centroid(v), K));
        }
    }
    
    return ans;
}

int best_path(int N, int K, int H[][2], int L[]) {
    
    for (int i = 0; i < N - 1; i++) {
        adj[H[i][0]].pb({H[i][1], L[i]});
        adj[H[i][1]].pb({H[i][0], L[i]});
    }
    FILL(best, INF);
    FILL(bestTmp, INF);
    best[0] = bestTmp[0] = 0;
    
    int ans = solve(centroid(0), K);
    return ans == INF ? -1 : ans;
}

int N, K;
int H[MAX][2], L[MAX];

int dist[MAX], distE[MAX];

void dfs1(int u, int prev) {
    for (pii e : adj[u]) {
        int v = e.f;
        int w = e.s;
        if (v != prev) {
            dist[v] = dist[u] + w;
            distE[v] = distE[u] + 1;
            dfs1(v, u);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d%d%d", &H[i][0], &H[i][1], &L[i]);
    }
    
    int ans = best_path(N, K, H, L);
    printf("%d\n", ans);
    
    ans = INF;
    for (int i = 0; i < N; i++) {
        dist[i] = distE[i] = 0;
        dfs1(i, -1);
        for (int j = 0; j < N; j++) {
            if (dist[j] == K) {
                ans = min(ans, distE[j]);
            }
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
    
    return 0;
}
