/*
 Solution to COCI '17 Contest 4 #4 Vođe by Ava Pun
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 5005;

int N, M, K;
bool team[MAX];
int dp[MAX][MAX];

inline bool query(int l, int r, bool val, int pref[]) {
    r = min(r, M - 1);
    return ((r - l + 1) * !val - (pref[l] - pref[r + 1])) != 0;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &team[i]);
    }
    
    for (int j = M - 2; j >= 0; j--) {
        for (int i = 1; i <= N; i++) {
            dp[i][j] = query(j + 1, j + K, !(team[i] ^ team[i % N + 1]), dp[i % N + 1]) + dp[i][j + 1];
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", !(query(0, 0, 1, dp[i]) ^ team[i]));
    }
    printf("\n");

    return 0;
}
