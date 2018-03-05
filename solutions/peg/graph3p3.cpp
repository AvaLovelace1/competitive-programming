/*
 Solution to Cable TV by Ava Pun
 Key concepts: graph theory, minimum spanning tree, Kruskal's
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piii;

int N, M;
piii edges[10005];
int par[105];
int ranks[105];

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

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b, c, d;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        edges[i] = make_pair(make_pair(d, c), make_pair(a, b));
    }
    
    sort(edges, edges + M);

    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    
    int cost = 0, danger = 0;
    for (int i = 0; i < M; i++) {
        d = edges[i].first.first;
        c = edges[i].first.second;
        a = edges[i].second.first;
        b = edges[i].second.second;
        if (Union(a, b)) {
            cost += c;
            danger += d;
        }
    }
    
    printf("%d %d", danger, cost);
    
    return 0;
}
