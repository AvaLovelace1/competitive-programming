/*
 Solution to CCC '10 S4 - Animal Farm by Ava Pun
 Key concepts: minimum spanning tree, Kruskal's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int M;
map<pii, piii> fences;
vector<piii> edges;
int parent[101];
int ranks[101] = {};

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

int krus() {
    for (int i = 0; i <= M; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    int count = 0;
    int outside = 0;
    int outsideW = 0;
    for (piii e : edges) {
        int x = e.second.first;
        int y = e.second.second;
        int w = e.first;
        if (Find(x) != Find(y)) {
            count += w;
            Union(x, y);
            if (x == 0 || y == 0) {
                outside++;
                outsideW = w;
            }
        }
    }
    if (outside == 1) {
        count -= outsideW;
    }
    return count;
}

int main() {
    
    scanf("%d", &M);
    int e, a;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &e);
        int corners[e];
        for (int j = 0; j < e; j++) {
            scanf("%d", &corners[j]);
        }
        for (int j = 0; j < e; j++) {
            scanf("%d", &a);
            int x = min(corners[j], corners[j + 1 < e ? j + 1 : 0]);
            int y = max(corners[j], corners[j + 1 < e ? j + 1 : 0]);
            if (fences.find({x, y}) == fences.end()) {
                fences[{x, y}].first = a;
                fences[{x, y}].second.first = i;
                fences[{x, y}].second.second = 0;
            } else {
                fences[{x, y}].second.second = i;
            }
        }
    }
    
    for (auto n : fences) {
        edges.push_back(n.second);
    }
    
    printf("%d", krus());
    
    return 0;
}
