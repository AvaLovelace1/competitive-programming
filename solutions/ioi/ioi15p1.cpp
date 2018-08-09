/*
 Solution to IOI '15 P1 - Boxes with Souvenirs by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;

int N, K, L, arr[MAX];
ll dp[2][MAX];

long long delivery(int N, int K, int L, int positions[]) {
    
    for (int i = N; i >= 1; i--) {
        arr[i] = positions[i - 1];
    }
    
    for (int i = 1; i <= N; i++) {
        dp[0][i] = dp[0][max(0, i - K)] + 2 * arr[i];
    }
    for (int i = N; i >= 1; i--) {
        dp[1][i] = dp[1][min(N + 1, i + K)] + 2 * (L - arr[i]);
    }
    
    ll ans = INT64_MAX;
    for (int i = 0; i <= N; i++) {
        ans = min(ans, dp[0][i] + dp[1][i + 1]);
        ans = min(ans, dp[0][i] + dp[1][min(N + 1, i + K + 1)] + L);
    }
    
    return ans;
}

int main() {
    
    scanf("%d%d%d", &N, &K, &L);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%lld\n", delivery(N, K, L, arr));
    
    return 0;
}
