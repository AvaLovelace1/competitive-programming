/*
 Solution to Favorite Numbers by Ava Pun
 Key concepts: implementation, binary search
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[100001];

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr + N);
    
    scanf("%d", &Q);
    int n;
    while (Q--) {
        scanf("%d", &n);
        auto itr1 = lower_bound(arr, arr + N, n);
        auto itr2 = upper_bound(arr, arr + N, *itr1);
        printf("%d %ld\n", *itr1, itr2 - itr1);
    }
    
    return 0;
    
}
