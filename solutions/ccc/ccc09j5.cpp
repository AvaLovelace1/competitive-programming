/*
 Solution to CCC '09 J5 - Degrees Of Separation by Ava Pun
 Key concepts: graph theory, BFS
 */

#include <bits/stdc++.h>

using namespace std;

unordered_set<int> adj[51];
unordered_set<int> s;
bool vis[51];
int dist[51];
queue<int> q;

void add(int a, int b) {
    adj[a].insert(b);
    adj[b].insert(a);
}

int main() {
    
    add(2, 6);
    add(1, 6);
    add(6, 7);
    add(7, 8);
    add(8, 9);
    add(9, 10);
    add(10, 11);
    add(11, 12);
    add(9, 12);
    add(12, 13);
    add(13, 14);
    add(16, 18);
    add(16, 17);
    add(17, 18);
    add(13, 15);
    add(15, 3);
    add(3, 5);
    add(3, 4);
    add(4, 5);
    add(3, 6);
    add(4, 6);
    add(5, 6);
    
    char c;
    scanf(" %c", &c);
    
    int a, b;
    while (c != 'q') {
        switch (c) {
            case 'i':
                scanf("%d%d", &a, &b);
                add(a, b);
                break;
            case 'd':
                scanf("%d%d", &a, &b);
                adj[a].erase(b);
                adj[b].erase(a);
                break;
            case 'n':
                scanf("%d", &a);
                printf("%ld\n", adj[a].size());
                break;
            case 'f':
                scanf("%d", &a);
                s.clear();
                for (int i : adj[a]) {
                    for (int j : adj[i]) {
                        if (j != a && adj[a].find(j) == adj[a].end()) {
                            s.insert(j);
                        }
                    }
                }
                printf("%ld\n", s.size());
                break;
            case 's':
                scanf("%d%d", &a, &b);
                fill(dist, dist + 51, INT_MAX);
                fill(vis, vis + 51, 0);
                dist[a] = 0;
                vis[a] = true;
                q.push(a);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (int n : adj[x]) {
                        if (!vis[n]) {
                            vis[n] = true;
                            dist[n] = dist[x] + 1;
                            q.push(n);
                        }
                    }
                }
                if (dist[b] == INT_MAX) {
                    printf("Not connected\n");
                } else {
                    printf("%d\n", dist[b]);
                }
                break;
        }
        scanf(" %c", &c);
    }
    
    return 0;
    
}
