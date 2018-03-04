/*
 Solution to CCC '01 S3 - Strategic Bombing by Ava Pun
 Key concepts: graph theory
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> adj[27];
vector<pii> edges;
bool vis[27];

void dfs(int n) {
    for (int i : adj[n]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    
    char a, b;
    scanf("%c%c", &a, &b);
    while (a != '*') {
        edges.push_back({a - 'A', b - 'A'});
        adj[a - 'A'].push_back(b - 'A');
        adj[b - 'A'].push_back(a - 'A');
        scanf(" %c%c", &a, &b);
    }
    
    int count = 0;
    for (pii i : edges) {
        int x = i.first;
        int y = i.second;
        adj[x].erase(find(adj[x].begin(), adj[x].end(), y));
        adj[y].erase(find(adj[y].begin(), adj[y].end(), x));
        fill(vis, vis + 27, 0);
        vis[0] = true;
        dfs(0);
        if (!vis[1]) {
            printf("%c%c\n", x + 'A', y + 'A');
            count++;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    printf("There are %d disconnecting roads.", count);
    
    return 0;
    
}
