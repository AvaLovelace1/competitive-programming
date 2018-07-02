/*
 Solution to CCO '18 P3 - Fun Palace by Ava Pun
 Key concepts: dynamic programming, prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int N, E, M;
pii arr[MAX];
int dp[2][20005];

inline int get(int i, int j) {
    return dp[i][j] - j;
}

int main() {

    scanf("%d%d", &N, &E);
    M = E;
    for (int i = 2; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
        M = max(M, max(arr[i].f, arr[i].s));
    }
    M *= 2;
    
    for (int i = 0; i <= M; i++) {
        dp[1][i] = i < E ? 0 : -INF;
    }
    for (int i = 2; i <= N; i++) {
        int n = i & 1;
        for (int j = 0; j <= M; j++) {
            dp[!n][j] += j;
        }
        for (int j = 1; j <= M; j++) {
            dp[!n][j] = max(dp[!n][j], dp[!n][j - 1]);
        }
        for (int j = 0; j <= M; j++) {
            if (j >= arr[i].f + arr[i].s) {
                dp[n][j] = get(!n, j);
            } else if (j >= arr[i].s) {
                dp[n][j] = get(!n, j - arr[i].s);
            } else {
                dp[n][j] = max(get(!n, j + arr[i].f) + arr[i].f, dp[!n][arr[i].f - 1]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(ans, dp[N & 1][i] + i);
    }
    printf("%d\n", ans);
    
    return 0;
}
