/*
 Solution to A Noisy Class by Ava Pun
 Key concepts: graph theory, topological sort
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> adj[10001];
int indeg[10001] = {};

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        if (adj[a].find(b) == adj[a].end()) {
            adj[a].insert(b);
            indeg[b]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        count++;
        for (int i : adj[x]) {
            indeg[i]--;
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
    }
    
    printf(count == N ? "Y" : "N");
    
    return 0;
}
