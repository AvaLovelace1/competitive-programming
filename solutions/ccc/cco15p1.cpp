/*
 Solution to CCO '15 P1 - Hungry Fox by Ava Pun
 Key concepts: greedy algorithms
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int N, W;
int arr[100001];

int main() {
    
    scanf("%d%d", &N, &W);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr + N);
    
    ll minN = 0, maxN = 0;
    
    int start = (int) (lower_bound(arr, arr + N, W) - arr);
    
    if (start >= 0 && start < N) {
        minN += arr[start] - W;
    }
    for (int i = start + 1; i < N; i++) {
        minN += arr[i] - arr[i - 1];
    }
    if (start - 1 >= 0 && start - 1 < N) {
        minN += W - arr[start - 1];
    }
    for (int i = start - 2; i >= 0; i--) {
        minN += arr[i + 1] - arr[i];
    }
    
    int prev, idx, add, n;
    ll sum;
    prev = W, idx = 0, add = N - 1, n = 1, sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += max(abs(arr[idx] - prev), abs(arr[idx] - W));
        prev = arr[idx];
        idx += add * n;
        add--;
        n = -n;
    }
    
    maxN = sum;
    prev = W, idx = N - 1, add = N - 1, n = -1, sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += max(abs(arr[idx] - prev), abs(arr[idx] - W));
        prev = arr[idx];
        idx += add * n;
        add--;
        n = -n;
    }
    
    maxN = max(maxN, sum);
    
    printf("%lld %lld", minN, maxN);
    
    return 0;
}
