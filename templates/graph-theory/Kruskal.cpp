/*
 ~ Kruskal's Minimum Spanning Tree Algorithm ~
 (with disjoint set data structure)
 
 Finds the minimum spanning tree of a graph.
 Easier to type than Prim's IMO.
 
 Time complexity: O(ElogE)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int MAXE = 1e6 + 5;

int N, M;
piii edges[MAXE];
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
        return false;
    }
    
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
    return true;
    
}

int krus() {
    
    sort(edges, edges + M);
    fill(ranks, ranks + N + 1, 0);
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    
    int ans = 0;
    for (int i = 0; i < M; i++) {
        piii e = edges[i];
        int u = e.second.first;
        int v = e.second.second;
        int w = e.first;
        if (Union(u, v)) {
            ans += w;
        }
    }
    
    return ans;

}

int main() {

    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &edges[i].second.first, &edges[i].second.second, &edges[i].first);
    }
    
    printf("Weight of minimum spanning tree: %d\n", krus());
    
    return 0;
    
}
