/*
 Solution to The Cake is a Dessert by Ava Pun
 Key concepts: 2D difference array, 2D prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MAX = 5005;

int N, M, K, Q;
ll arr1[MAX][MAX], arr2[MAX][MAX];

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    
    int x1, y1, x2, y2;
    while (K--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        arr1[x1][y1]++;
        arr1[x1][y2 + 1]--;
        arr1[x2 + 1][y1]--;
        arr1[x2 + 1][y2 + 1]++;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr2[i][j] = arr2[i - 1][j] + arr2[i][j - 1] - arr2[i - 1][j - 1] + arr1[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr1[i][j] = arr1[i - 1][j] + arr1[i][j - 1] - arr1[i - 1][j - 1] + arr2[i][j];
        }
    }
    
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%lld\n", arr1[x2][y2] - arr1[x1 - 1][y2] - arr1[x2][y1 - 1] + arr1[x1 - 1][y1 - 1]);
    }
    
    return 0;
}
