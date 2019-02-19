/*
 Solution to 315 - Network by Ava Pun
 Key concepts: Tarjan's articulation points
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef vector<int> vi;
const int MAX = 105;

int N;
set<int> adj[MAX];
int dfn[MAX], lo[MAX];
bool vis[MAX];
int cnt = 0, nArts = 0;

void tarj(int u, int p) {
    dfn[u] = lo[u] = ++cnt;
    vis[u] = 1;
    int children = 0;
    bool isArt = 0;
    for (int v : adj[u]) {
        if (!vis[v]) {
            children++;
            tarj(v, u);
            lo[u] = min(lo[u], lo[v]);
            if ((dfn[u] == 1 && children > 1) || (dfn[u] != 1 && lo[v] >= dfn[u])) {
                isArt = 1;
            }
        } else if (v != p && dfn[v] < dfn[u]) {
            lo[u] = min(lo[u], dfn[v]);
        }
    }
    if (isArt) {
        nArts++;
    }
}

int main() {
    
    scanf("%d", &N);
    while (N) {
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        FILL(vis, 0);
        cnt = 0, nArts = 0;
        int a, b;
        scanf("%d", &a);
        char tmp;
        while (a) {
            tmp = ' ';
            while (tmp != '\n') {
                scanf("%d%c", &b, &tmp);
                adj[a].insert(b);
                adj[b].insert(a);
            }
            scanf("%d", &a);
        }
        tarj(1, -1);
        printf("%d\n", nArts);
        scanf("%d", &N);
    }
    
    return 0;
}
