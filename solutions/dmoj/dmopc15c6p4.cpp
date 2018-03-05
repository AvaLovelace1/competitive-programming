/*
 Solution to DMOPC '15 Contest 6 P4 - Line Graph by Ava Pun
 Key concepts: graph theory, minimum spanning tree, Kruskal's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e5 + 5;

int N, K;
pii edges[MAX];
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

int main() {
    
    scanf("%d%d", &N, &K);
    int a;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &a);
        edges[i] = {a, i};
    }
    
    sort(edges, edges + N - 1);
    for (int i = 0; i < N; i++) {
        par[i] = i;
    }
    fill(ranks, ranks + N, 0);
    int ans = 0;
    
    for (int i = 0; i + K < N; i++) {
        Union(i, i + K);
    }
    
    for (int i = 0; i < N - 1; i++) {
        pii e = edges[i];
        if (Union(e.second, e.second + 1)) {
            ans += e.first;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}
