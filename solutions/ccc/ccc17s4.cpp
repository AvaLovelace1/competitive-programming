/*
 Solution to CCC '17 S4 - Minimum Cost Flow by Ava Pun
 Key concepts: minimum spanning tree, Kruskal's
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pair<int, bool>, pii> piii;

int N, M, D;
vector<piii> edges;
int parent[100001];
int ranks[100001];

int Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int a, int b) {
    int a0 = Find(a);
    int b0 = Find(b);
    if (ranks[a0] < ranks[b0]) {
        parent[a0] = b0;
    } else if (ranks[b0] < ranks[a0]) {
        parent[b0] = a0;
    } else {
        parent[b0] = a0;
        ranks[a0]++;
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    fill(ranks, ranks + N + 1, 0);
}

int krus() {
    sort(edges.begin(), edges.end());
    init();
    int count = 0, maxN = 0;
    bool isNew = false;
    for (piii e : edges) {
        int u = e.second.first;
        int v = e.second.second;
        if (Find(u) != Find(v)) {
            Union(u, v);
            maxN = e.first.first;
            isNew = e.first.second;
            if (e.first.second) {
                count++;
            }
        }
    }
    init();
    if (isNew) {
        for (piii e : edges) {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first.first;
            if (Find(u) != Find(v)) {
                if (w < maxN || (w == maxN && !e.first.second)) {
                    Union(u, v);
                } else if (w <= D && !e.first.second) {
                    count--;
                    break;
                }
            }
        }
    }
    return count;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &D);
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({{c, i > N - 1}, {a, b}});
    }
    
    printf("%d", krus());
    
    return 0;
    
}
