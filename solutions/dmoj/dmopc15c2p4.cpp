/*
 Solution to DMOPC '15 Contest 2 P4 - Personal Assistant by Ava Pun
 Key concepts: dynamic programming, weighted scheduling problem
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MAX = 1e5 + 5;

int N;
ll R[MAX], L[MAX], H[MAX];
ll dp[MAX];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld%lld", &R[i], &L[i], &H[i]);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        int start = 0, end = N, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (R[mid] >= R[i] + L[i]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        dp[i] = max(H[i] + dp[start], dp[i + 1]);
    }

    printf("%lld", dp[0]);
    
    return 0;
    
}
