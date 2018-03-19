/*
 Solution to CCO '01 P6 - Election Night by Ava Pun
 Key concepts: graph theory, max flow, Dinic's
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 105;

int N, M, S = 0, T;
set<int> arr[MAX];
int maxN[MAX];
piii edges[MAX * MAX];
int last[2 * MAX], dist[2 * MAX];
int cnt = 0;

bool bfs() {
    
    FILL(dist, INF);
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = last[u]; i != -1; i = edges[i].s) {
            int v = edges[i].f.f;
            int w = edges[i].f.s;
            if (dist[v] == INF && w) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist[T] != INF;
}

int dfs(int u, int flow) {
    
    if (u == T) {
        return flow;
    }
    
    int ans = 0;
    for (int i = last[u]; i != -1; i = edges[i].s) {
        int v = edges[i].f.f;
        int w = edges[i].f.s;
        if (dist[v] == dist[u] + 1 && w) {
            int res = dfs(v, min(flow, w));
            ans += res;
            edges[i].f.s -= res;
            edges[i ^ 1].f.s += res;
            flow -= res;
            if (!flow) {
                break;
            }
        }
    }
    
    return ans;
}

int dinic() {
    int maxFlow = 0;
    while (bfs()) {
        maxFlow += dfs(S, INF);
    }
    return maxFlow;
}

void addEdge(int a, int b, int d) {
    edges[cnt] = {{b, d}, last[a]};
    last[a] = cnt++;
    edges[cnt] = {{a, 0}, last[b]};
    last[b] = cnt++;
}

int main() {
    
    scanf("%d%d", &N, &M);
    
    int n, x;
    while (N != 0 || M != 0) {
        
        T = N + M + 1;
        FILL(maxN, 0);
        for (int i = 1; i < MAX; i++) {
            arr[i].clear();
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d", &n);
            for (int j = 1; j <= n; j++) {
                scanf("%d", &x);
                arr[x].insert(i);
                if (n == 1) {
                    maxN[x]++;
                }
            }
        }

        int winner = -1;
        for (int i = 1; i <= M; i++) {
            bool found = true;
            for (int j = 1; j <= M; j++) {
                if (j != i) {
                    if (arr[j].size() >= maxN[i]) {
                        found = false;
                        break;
                    }
                }
            }
            if (found) {
                winner = i;
                break;
            }
        }
        
        if (winner != -1) {
            for (int i = 1; i <= M; i++) {
                if (i == winner) {
                    printf("Candidate %d will become president.\n", i);
                } else {
                    printf("Candidate %d will not become president.\n", i);
                }
            }
        } else {
            for (int i = 1; i <= M; i++) {
                if (arr[i].empty() || (arr[i].size() == 1 && N != 1)) {
                    printf("Candidate %d will not become president.\n", i);
                } else {
                    cnt = 0;
                    FILL(last, -1);
                    for (int j = 1; j <= M; j++) {
                        if (j != i) {
                            addEdge(S, j, (int) arr[i].size() - 1);
                            for (int k : arr[j]) {
                                if (arr[i].find(k) == arr[i].end()) {
                                    addEdge(j, k + M, 1);
                                }
                            }
                        }
                    }
                    for (int j = 1; j <= N; j++) {
                        addEdge(j + M, T, 1);
                    }
                    if (dinic() < N - (int) arr[i].size()) {
                        printf("Candidate %d will not become president.\n", i);
                    } else {
                        printf("Candidate %d may become president.\n", i);
                    }
                }
            }
        }
        
        printf("\n");
        scanf("%d%d", &N, &M);
    }
    
    return 0;
}
