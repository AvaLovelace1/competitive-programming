/*
 Solution to CCC '05 S3 - Quantum Operations by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N, R, C;
int arr[1030][1030];
int tmp[1030][1030];
int prod[1030][1030];

int main() {
    
    scanf("%d", &N);
    
    int r, c, prevr, prevc;
    scanf("%d%d", &r, &c);
    R = r, C = c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    N--;
    prevr = r, prevc = c;
    
    while (N--) {
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                scanf("%d", &tmp[i][j]);
            }
        }
        
        R *= r, C *= c;
        for (int i = 1; i <= prevr; i++) {
            for (int j = 1; j <= prevc; j++) {
                for (int k = 1; k <= r; k++) {
                    for (int l = 1; l <= c; l++) {
                        prod[k + (i - 1) * r][l + (j - 1) * c] = arr[i][j] * tmp[k][l];
                    }
                }
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                arr[i][j] = prod[i][j];
            }
        }
        prevr = R, prevc = C;
    }
    
    int maxN = INT_MIN, minN = INT_MAX, maxC = INT_MIN, minC = INT_MAX, maxR = INT_MIN, minR = INT_MAX;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            maxN = max(maxN, prod[i][j]);
            minN = min(minN, prod[i][j]);
        }
    }
    int sum;
    for (int i = 1; i <= R; i++) {
        sum = 0;
        for (int j = 1; j <= C; j++) {
            sum += prod[i][j];
        }
        maxR = max(maxR, sum);
        minR = min(minR, sum);
    }
    for (int i = 1; i <= C; i++) {
        sum = 0;
        for (int j = 1; j <= R; j++) {
            sum += prod[j][i];
        }
        maxC = max(maxC, sum);
        minC = min(minC, sum);
    }
    
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", maxN, minN, maxR, minR, maxC, minC);
    
    return 0;
}
