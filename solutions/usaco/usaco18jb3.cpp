/*
 Solution to USACO '18 January B3 - Out of Place by Ava Pun
 Key concepts: ad hoc
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N;
int arr[105], sorted[105];

int main() {
    
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }
    
    sort(sorted, sorted + N);
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (sorted[i] != arr[i]) {
            count++;
        }
    }
    
    printf("%d", max(0, count - 1));
    
    return 0;
}
