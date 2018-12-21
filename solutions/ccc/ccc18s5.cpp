/*
 Solution to CCC '18 S5 - Maximum Strategic Savings by Ava Pun
 Key concepts: minimum spanning tree, Kruskal's
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, P, Q;
piii edges[2 * MAX];
int edgeCnt = 0;
ll total = 0;
int parentP[MAX], parentC[MAX], ranksP[MAX], ranksC[MAX];

int Find(int x, int parent[]) {
    if (x != parent[x]) {
        parent[x] = Find(parent[x], parent);
    }
    return parent[x];
}

bool Union(int a, int b, int parent[], int ranks[]) {
    a = Find(a, parent);
    b = Find(b, parent);
    if (a == b) {
        return false;
    }
    if (ranks[a] < ranks[b]) {
        parent[a] = b;
    } else if (ranks[b] < ranks[a]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        ranks[a]++;
    }
    return true;
}

int main() {
    
    scanf("%d%d%d%d", &N, &M, &P, &Q);
    int a, b, d;
    for (int i = 1; i <= P; i++) {
        scanf("%d%d%d", &a, &b, &d);
        edges[edgeCnt++] = {{d, 0}, {a, b}};
        total += (ll) N * d;
    }
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d", &a, &b, &d);
        edges[edgeCnt++] = {{d, 1}, {a, b}};
        total += (ll) M * d;
    }
    sort(edges, edges + edgeCnt);
    
    for (int i = 1; i <= N; i++) {
        parentP[i] = i;
    }
    for (int i = 1; i <= M; i++) {
        parentC[i] = i;
    }
    
    ll ans = 0;
    for (int i = 0; i < edgeCnt; i++) {
        int w = edges[i].first.first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (edges[i].first.second) {
            if (Union(u, v, parentP, ranksP)) {
                ans += (ll) w * M;
                N--;
            }
        } else {
            if (Union(u, v, parentC, ranksC)) {
                ans += (ll) w * N;
                M--;
            }
        }
    }
    
    printf("%lld", total - ans);
    
    return 0;
}
