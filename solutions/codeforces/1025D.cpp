/*
 Solution to Recovering BST by Ava Pun
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
const int MOD = 998244353;
const int MAX = 705;

int N;
int arr[MAX];
bool dp[MAX][MAX][2], done[MAX][MAX][2];

int solve(int l, int r, bool x) {
    if (!done[l][r][x]) {
        done[l][r][x] = 1;
        if (l > r) {
            dp[l][r][x] = 1;
        } else {
            int root = x ? r + 1 : l - 1;
            for (int i = l; i <= r && !dp[l][r][x]; i++) {
                if (__gcd(arr[root], arr[i]) > 1) {
                    dp[l][r][x] = solve(l, i - 1, 1) && solve(i + 1, r, 0);
                }
            }
        }
    }
    return dp[l][r][x];
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    bool ans = 0;
    for (int i = 1; i <= N && !ans; i++) {
        ans = solve(1, i - 1, 1) && solve(i + 1, N, 0);
    }
    printf(ans ? "Yes\n" : "No\n");
    
    return 0;
}
