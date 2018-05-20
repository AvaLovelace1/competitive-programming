/*
 Solution to CCO '18 P2 - Wrong Answer by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define FILL(a, b) memset(a, b, sizeof(a))

const int MAX = 105;

int N;
int arr[MAX][MAX];

int main() {
    
    N = 100;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            arr[i][j] = 1;
        }
    }
    
    for (int i = 1; i + 2 <= N; i++) {
        arr[i][i + 2] = 100;
    }
    for (int i = 2; i + 1 <= N; i += 2) {
        arr[i][i + 1] = 100;
    }
    arr[2][3] = 1;
    arr[1][3] = 2;
    arr[1][4] = 2;
    
    printf("%d\n", N);
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
