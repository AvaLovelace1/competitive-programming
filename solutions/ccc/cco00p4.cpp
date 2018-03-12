/*
 Solution to CCO '00 P4 - Routing by Ava Pun
 Key concepts: graph theory, Floyd-Warshall's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3F3F3F3F;

int N, W, P;
int dist[101][101];

int main() {
    
    memset(dist, INF, sizeof(dist));
    
    scanf("%d%d%d", &N, &W, &P);
    
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    
    int a, b, w;
    while (W--) {
        scanf("%d%d%d", &a, &b, &w);
        dist[a][b] = dist[b][a] = w;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
    
    while (P--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
    
    return 0;
    
}
