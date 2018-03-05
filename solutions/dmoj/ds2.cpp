/*
 Solution to Disjoint Set Test by Ava Pun
 Key concepts: graph theory, disjoint set, minimum spanning tree, Kruskal's
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
pii edges[1000005];
vector<int> mst;
int par[100005];
int ranks[100005];

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

bool kruskal() {
    
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    
    for (int i = 1; i <= M; i++) {
        pii e = edges[i];
        if (Union(e.first, e.second)) {
            mst.push_back(i);
        }
    }
    
    if (mst.size() != N - 1) {
        return false;
    } else {
        return true;
    }
    
}

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &a, &b);
        edges[i] = {a, b};
    }
    
    bool possible = kruskal();
    
    if (possible) {
        for (int i : mst) {
            printf("%d\n", i);
        }
    } else {
        printf("Disconnected Graph");
    }
    
}
