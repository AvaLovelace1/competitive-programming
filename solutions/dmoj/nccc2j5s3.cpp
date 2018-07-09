/*
 Solution to Mock CCC '18 Contest 2 J5/S3 - A Coloring Problem by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<bool, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, M;
char arr[31][31];
ll dp[31][31];
int cnt[31];

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 'B') {
                for (int k = 1; k <= i; k++) {
                    for (int l = 1; l <= j; l++) {
                        if (arr[k][l] == 'R') {
                            printf("0\n");
                            return 0;
                        } else {
                            arr[k][l] = 'B';
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 'B') {
                cnt[i]++;
            }
        }
    }
    
    dp[0][M] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j < cnt[i]) {
                dp[i][j] = 0;
            } else {
                bool good = 1;
                for (int k = 1; k <= j; k++) {
                    if (arr[i][k] == 'R') {
                        good = 0;
                    }
                }
                if (good) {
                    for (int k = j; k <= M; k++) {
                        dp[i][j] += dp[i - 1][k];
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int j = 0; j <= M; j++) {
        ans += dp[N][j];
    }
    printf("%lld\n", ans);
    
    return 0;
}
