/*
 Solution to DMOPC '18 Contest 3 P2 - Bob and French Class by Ava Pun
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
const int MAX = 1e5 + 5;

int N;
int arr[2][MAX];
int dp[3][MAX];

int main() {
    
    scanf("%d", &N);
    for (int a = 0; a <= 1; a++) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[a][i]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j >= 0; j--) {
            if (j != 0) {
                dp[j][i] = dp[j - 1][i - 1] + arr[0][i];
            } else {
                dp[j][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1])) + arr[1][i];
            }
        }
    }
    printf("%d\n", max(dp[0][N], max(dp[1][N], dp[2][N])));
    
    return 0;
}
