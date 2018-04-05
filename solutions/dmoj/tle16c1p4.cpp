/*
 Solution to TLE '16 Contest 1 P4 - Microwaves Again! by Ava Pun
 Key concepts: Floyd-Warshall's, brute force
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3F3F3F3F;

int N, M, K;
int arr[101];
int dist[101][101];
bitset<101> rooms[101];

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    memset(dist, INF, sizeof(dist));
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        dist[i][i] = 0;
    }
    
    int a, b, d;
    while (M--) {
        scanf("%d%d%d", &a, &b, &d);
        dist[a][b] = dist[b][a] = d;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++) {
                dist[u][v] = min(dist[u][k] + dist[k][v], dist[u][v]);
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] <= K) {
                rooms[i][j] = 1;
            }
        }
    }
    
    int maxSum = INT_MIN;
    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            for (int k = j + 1; k <= N; k++) {
                bitset<101> bs;
                bs |= rooms[i] | rooms[j] | rooms[k];
                int sum = 0;
                for (int l = 1; l <= N; l++) {
                    if (bs[l]) {
                        sum += arr[l];
                    }
                }
                maxSum = max(maxSum, sum);
            }
        }
    }
    
    printf("%d", maxSum);

    return 0;
}
