/*
 Solution to USACO '18 January G1 - MooTube by Ava Pun
 Key concepts: graph theory, disjoint set, offline queries
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MAX = 1e5 + 5;

int N, Q;
piii edges[MAX], queries[MAX];
int answers[MAX];
int parent[MAX], ranks[MAX], size[MAX];

bool comp(piii a, piii b) {
    return a.second > b.second;
}

int Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int a, int b) {
    
    a = Find(a);
    b = Find(b);
    if (ranks[a] < ranks[b]) {
        parent[a] = b;
        size[b] = size[a] + size[b];
    } else if (ranks[b] < ranks[a]) {
        parent[b] = a;
        size[a] = size[a] + size[b];
    } else {
        parent[b] = a;
        ranks[a]++;
        size[a] = size[a] + size[b];
    }
    
}

int main() {
    
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d%d%d", &edges[i].second.first, &edges[i].second.second, &edges[i].first);
    }
    sort(edges, edges + N - 1, greater<piii>());
    
    fill(ranks, ranks + N + 1, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &queries[i].second.first, &queries[i].second.second);
        queries[i].first = i;
    }
    sort(queries, queries + Q, comp);
    
    int idx = 0;
    for (int i = 0; i < Q; i++) {
        int w = queries[i].second.first;
        int u = queries[i].second.second;
        while (edges[idx].first >= w) {
            Union(edges[idx].second.first, edges[idx].second.second);
            idx++;
        }
        answers[queries[i].first] = size[Find(u)] - 1;
    }
    
    for (int i = 0; i < Q; i++) {
        printf("%d\n", answers[i]);
    }
    
    return 0;
}
