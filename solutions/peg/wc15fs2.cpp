/*
 Solution to WC15 Finals - Hydration by Ava Pun
 Key concepts: binary search, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int cows[1000001];
int troughs[1000001];
int num[1000001];

bool check(int n) {
    fill(num, num + M, 0);
    for (int i = N - 1; i >= 0; i--) {
        int start = 0, end = M, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (troughs[mid] > cows[i] || num[mid] >= n) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        start--;
        if (start != -1 && cows[i] - troughs[start] <= K) {
            num[start]++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cows[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &troughs[i]);
    }
    
    sort(cows, cows + N);
    sort(troughs, troughs + M);

    int start = 1, end = N + 1, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (check(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    printf("%d", start != N + 1 ? start : -1);
    
    return 0;
}
