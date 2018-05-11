/*
 Solution to CCC '10 S3 - Firehose by Ava Pun
 Key concepts: greedy algorithms, binary search
 */
 
#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1001];

bool check(int n) {
    int count, dist, curr;
    for (int i = 0; i < N; i++) {
        count = 1, dist = 0;
        curr = arr[i];
        for (int j = 0; j < N; j++) {
            int idx = (j + i) % N;
            dist += (arr[idx] - curr + 1000000) % 1000000;
            curr = arr[idx];
            if (dist > 2 * n) {
                count++;
                dist = 0;
            }
        }
        if (count <= K) {
            return true;
        }
    }
    return false;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &K);
    
    sort(arr, arr + N);
    
    int start = 0, end = 1e6, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (check(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    printf("%d", start);
    
    return 0;
}
