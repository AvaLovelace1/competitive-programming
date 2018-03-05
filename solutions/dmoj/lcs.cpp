/*
 Solution to Longest Common Subsequence by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int N, M;
int arr1[MAX], arr2[MAX];
int dp[MAX][MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d", &arr2[i]);
    }
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (arr1[i] == arr2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    printf("%d", dp[N][M]);
    
    return 0;
}
