/*
 Solution to WC17 Finals - Cowmmunication Network by Ava Pun
 Key concepts: minimum spanning tree, Kruskal's
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
const int MAX = 2e5 + 5;

int N, M;
piii edges[MAX];
int par[MAX], ranks[MAX];

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) {
        return 0;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else if (ranks[a] > ranks[b]) {
        par[b] = a;
    } else {
        par[b] = a;
        ranks[a]++;
    }
    return 1;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &edges[i].s.f, &edges[i].s.s, &edges[i].f);
    }
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    sort(edges + 1, edges + M + 1, greater<piii>());
    
    int cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= M; i++) {
        int u = edges[i].s.f, v = edges[i].s.s, w = edges[i].f;
        if (Union(u, v)) {
            ans += w;
            cnt++;
        } else if (w > 0) {
            ans += w;
        }
    }
    
    if (cnt == N - 1) {
        printf("%lld\n", ans);
    } else {
        printf("Impossible\n");
    }
    
    return 0;
}
