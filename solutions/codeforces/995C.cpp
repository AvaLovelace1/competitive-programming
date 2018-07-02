/*
 Solution to Leaving the Bar by Ava Pun
 Key concepts: greedy algorithms, math
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
pii arr[2 * MAX];
vii adj[2 * MAX];
vector<int> v = {1, 2};
int curr;
bool vis[2 * MAX];
int dist[2 * MAX];

inline ll distSq(pii v) {
    return (ll) v.f * v.f + (ll) v.s * v.s;
}

inline pii add(pii a, pii b) {
    return {a.f + b.f, a.s + b.s};
}

inline pii sub(pii a, pii b) {
    return {a.f - b.f, a.s - b.s};
}

inline bool check(pii a, pii b, bool plus, int lim) {
    if (!plus) {
        b.f = -b.f, b.s = -b.s;
    }
    return distSq(add(a, b)) <= (ll) lim * lim;
}

inline void findVecs(int lim) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (check(arr[v[i]], arr[v[j]], 0, lim)) {
                arr[curr] = sub(arr[v[i]], arr[v[j]]);
                adj[curr].pb({v[i], 1}), adj[curr].pb({v[j], -1});
                v.erase(v.begin() + j), v.erase(v.begin() + i);
                return;
            } else if (check(arr[v[i]], arr[v[j]], 1, lim)) {
                arr[curr] = add(arr[v[i]], arr[v[j]]);
                adj[curr].pb({v[i], 1}), adj[curr].pb({v[j], 1});
                v.erase(v.begin() + j), v.erase(v.begin() + i);
                return;
            }
        }
    }
}

void dfs(int u) {
    for (pii e : adj[u]) {
        int v = e.f, w = e.s;
        if (!vis[v]) {
            vis[v] = 1;
            dist[v] = dist[u] * w;
            dfs(v);
        }
    }
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    
    if (N == 1) {
        printf("1 ");
        return 0;
    }
    curr = N + 1;
    for (int i = 3; i <= N; i++) {
        v.pb(i);
        findVecs(1e6);
        v.pb(curr);
        curr++;
    }
    findVecs(1.5e6);
    
    fill(dist + 1, dist + curr + 1, 1);
    vis[curr] = 1;
    dfs(curr);
    
    for (int i = 1; i <= N; i++) {
        printf("%d ", dist[i]);
    }
    
    return 0;
}
