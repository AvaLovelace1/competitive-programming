/*
 Solution to Mock CCC '18 Contest 3 J4/S2 - A Median Problem by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[105][105];
int meds[105];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        sort(arr[i], arr[i] + N);
        meds[i] = arr[i][N / 2];
    }
    sort(meds, meds + N);
    
    printf("%d\n", meds[N / 2]);
    
    return 0;
}
