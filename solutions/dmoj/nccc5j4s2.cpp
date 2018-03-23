/*
 Solution to Mock CCC '18 Contest 5 J4/S2 - Carol's Cute Carols by Ava Pun
 Key concepts: simulation, implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1005];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
