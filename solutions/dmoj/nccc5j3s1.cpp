/*
 Solution to Mock CCC '18 Contest 5 J3/S1 - Carol's Cute Center by Ava Pun
 Key concepts: brute force, implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N, X;
int arr[105];
int tmp[3];

int main() {
    
    scanf("%d%d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                tmp[0] = arr[i], tmp[1] = arr[j], tmp[2] = arr[k];
                sort(tmp, tmp + 3);
                if (tmp[1] == X) {
                    ans++;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
