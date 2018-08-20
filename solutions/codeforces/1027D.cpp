/*
 Solution to Mouse Hunt by Ava Pun
 Key concepts: graph theory, DFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N;
int arr[MAX], adj[MAX], indeg[MAX];
vi comps[MAX];
bool vis[MAX];
set<int> ss;
int cnt = 0;

void dfs(int u) {
    if (!vis[u]) {
        vis[u] = 1;
        comps[cnt].pb(arr[u]);
        dfs(adj[u]);
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &adj[i]);
        indeg[adj[i]]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        ss.insert(i);
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ss.erase(u);
        indeg[adj[u]]--;
        if (indeg[adj[u]] == 0) {
            q.push(adj[u]);
        }
    }
    
    for (int i : ss) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans += *min_element(comps[i].begin(), comps[i].end());
    }
    
    printf("%d\n", ans);
    
    return 0;
}
