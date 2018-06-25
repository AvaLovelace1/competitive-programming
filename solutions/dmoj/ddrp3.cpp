/*
 Solution to Double Doors Regional P3 - Tudor and the Pusheens by Ava Pun
 Key concepts: BFS
 */
 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, M, S, T;
vi adj[MAX];
int dist[MAX];

int main() {

    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    scanf("%d%d", &S, &T);
    
    fill(dist, dist + N + 1, INF);
    
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    printf("%d\n", M - dist[T]);
    
    return 0;
}
