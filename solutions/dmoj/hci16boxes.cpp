/*
 Solution to Serial Killer by Ava Pun
 Key concepts: dynamic programming, longest increasing subsequence
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e6 + 1;

bool comp(pii a, pii b) {
    if (a.first == b.first) {
        return b < a;
    } else {
        return a < b;
    }
}

int N;
pii arr[MAX];
int dp[MAX];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    sort(arr + 1, arr + N + 1, comp);
    
    int len = 0;
    for (int i = 1; i <= N; i++) {
        int pos = (int) (lower_bound(dp, dp + len, arr[i].second) - dp);
        dp[pos] = arr[i].second;
        if (pos == len) {
            len++;
        }
    }
    printf("%d", len);
    
    return 0;
}
