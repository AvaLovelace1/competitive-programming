/*
 Solution to TLE '15 P2 - Microwaves by Ava Pun
 Key concepts: greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, int> pii;

int N, M, T;
pii arr[100001];
ll m[101];

int main() {
    
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 0; i < M; i++) {
        scanf("%lld%d", &arr[i].first, &arr[i].second);
    }
    
    sort(arr, arr + M);
    m[N] = -1;
    
    int maxIdx = N, minIdx = 0;
    ll ans = INT64_MAX;
    for (int i = 0; i < M; i++) {
        maxIdx = N, minIdx = 0;
        for (int j = 0; j < N; j++) {
            if (m[j] <= arr[i].first && m[j] > m[maxIdx]) {
                maxIdx = j;
            }
            if (m[j] < m[minIdx]) {
                minIdx = j;
            }
        }
        if (arr[i].first - m[minIdx] >= T) {
            ans = min(ans, m[minIdx]);
        }
        if (maxIdx == N) {
            m[minIdx] += arr[i].second;
        } else {
            m[maxIdx] = arr[i].first + arr[i].second;
        }
    }
    
    for (int j = 0; j < N; j++) {
        ans = min(ans, m[j]);
    }
    
    printf("%lld", ans);
    
    return 0;
}
