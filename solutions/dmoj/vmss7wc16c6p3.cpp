/*
 Solution to VM7WC '16 #6 Gold - Cold War Telecom by Ava Pun
 Key concepts: graph theory, articulation points, Tarjan's
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;
int N, M;
vector<int> adj[MAX];
int cnt = 0;
int dfn[MAX], low[MAX];
bool vis[MAX], inStack[MAX], art[MAX];

void tarj(int u) {
    dfn[u] = low[u] = cnt;
    vis[u] = true;
    cnt++;
    inStack[u] = true;
    int children = 0;
    for (int v : adj[u]) {
        if (!vis[v]) {
            children++;
            tarj(v);
            low[u] = min(low[u], low[v]);
            if (u == 1) {
                if (children > 1) {
                    art[u] = true;
                }
            } else if (low[v] >= dfn[u]) {
                art[u] = true;
            }
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    inStack[u] = false;
}

int main() {
    
    scanf("%d%d", &N, &M);
    
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    tarj(1);
    int num = 0;
    for (int i = 1; i <= N; i++) {
        if (art[i]) {
            num++;
        }
    }
    printf("%d\n", num);
    for (int i = 1; i <= N; i++) {
        if (art[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
