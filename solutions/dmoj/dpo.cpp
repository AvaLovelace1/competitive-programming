/*
 Solution to Matching by Ava Pun
 Key concepts: bitmask dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 250005;

int N;
int comp[25][25];
int dp[25][(1 << 21) + 5];

int solve(int i, int j) {
    int &ans = dp[i][j];
    if (ans == -1) {
        if (i == 0 && j == 0) {
            ans = 1;
        } else {
            ans = 0;
            for (int k = 1; k <= N; k++) {
                if (j & (1 << (k - 1)) && comp[i][k]) {
                    ans = (ans + solve(i - 1, j & ~(1 << (k - 1)))) % MOD;
                }
            }
        }
    }
    return ans;   
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &comp[i][j]);
        }
    }

    FILL(dp, -1);
    printf("%d\n", solve(N, (1 << N) - 1));
    
    return 0;
}
