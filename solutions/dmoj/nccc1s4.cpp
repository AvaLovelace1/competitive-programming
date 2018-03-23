/*
 Solution to Mock CCC '18 Contest 1 S4 - A Graph Problem by Ava Pun
 Key concepts: graph theory, point sweep, BFS
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;

int N, M, K, S, T;
vector<piii> adj[1005];
set<int> edges;
unordered_set<int> startp;
bool vis[1005];

int bfs(int start, int end, int k) {
    
    fill(vis, vis + N + 1, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (piii n : adj[x]) {
            int v = n.first;
            if (!vis[v] && k >= n.second.first && k <= n.second.second) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    
    return vis[end];
}

int main() {
    
    scanf("%d%d%d%d%d", &N, &M, &K, &S, &T);
    int a, b, c, d;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        adj[a].push_back({b, {c, d}});
        edges.insert(c);
        edges.insert(d + 1);
        startp.insert(c);
    }

    edges.insert(K + 1);
    
    int ans = 0, cnt = 0, prev = *edges.begin();
    for (int i : edges) {
        int curr = i;
        if (cnt != 0) {
            ans += (curr - prev) * bfs(S, T, prev);
        }
        if (startp.find(curr) != startp.end()) {
            cnt++;
        } else {
            cnt--;
        }
        prev = curr;
        if (i == K + 1) {
            break;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
