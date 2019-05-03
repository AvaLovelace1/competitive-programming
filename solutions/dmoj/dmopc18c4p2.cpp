/*
 Solution to  by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N;
int arr[705];
bool dp[2][705 * 705];

int main() {
    
    scanf("%d", &N);
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j - arr[i] >= 0) {
                dp[i & 1][j] |= dp[!(i & 1)][j - arr[i]];
                dp[i & 1][j] |= dp[!(i & 1)][j];
            }
        }
    }
    
    int ans = INF;
    for (int i = 0; i <= sum; i++) {
        if (dp[N & 1][i]) {
            ans = min(ans, abs(sum - 2 * i));
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
