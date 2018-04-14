/*
 Solution to VM7WC '16 #2 Gold - GGG by Ava Pun
 Key concepts: dynamic programming, longest common subsequence
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;
const int INF = 0x3F3F3F3F;

int N, M;
int arr1[MAX], arr2[MAX];
int dp[MAX];

int main() {
    
    scanf("%d", &N);
    fill(arr2, arr2 + MAX, INF);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &n);
        arr2[n] = i;
    }
    
    int len = 0;
    for (int i = 1; i <= N; i++) {
        if (arr2[arr1[i]] != INF) {
            int pos = (int) (lower_bound(dp, dp + len, arr2[arr1[i]]) - dp);
            dp[pos] = arr2[arr1[i]];
            if (pos == len) {
                len++;
            }
        }
    }
    printf("%d", len);
    
    return 0;
}
