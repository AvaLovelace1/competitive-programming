/*
 Solution to NOI '09 - Modified Treap by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, K;
pii key[75], p[75], freq[75];
int dp[75][75][75];

bool comp(pii a, pii b) {
    return key[a.s].f < key[b.s].f;
}

int getSum(int l, int r) {
    return freq[r].f - freq[l - 1].f;
}

int solve(int l, int r, int w) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r][w] == -1) {
        dp[l][r][w] = INF;
        for (int i = l; i <= r; i++) {
            if (p[i].f < w) {
                dp[l][r][w] = min(dp[l][r][w], solve(l, i - 1, w) + solve(i + 1, r, w) + getSum(l, r) + K);
            } else {
                dp[l][r][w] = min(dp[l][r][w], solve(l, i - 1, p[i].f) + solve(i + 1, r, p[i].f) + getSum(l, r));
                dp[l][r][w] = min(dp[l][r][w], solve(l, i - 1, w) + solve(i + 1, r, w) + getSum(l, r) + K);
            }
        }
    }
    return dp[l][r][w];
}

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &key[i].f);
        key[i].s = i;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[i].f);
        p[i].s = i;
    }
    sort(p + 1, p + N + 1);
    for (int i = 1; i <= N; i++) {
        p[i].f = i;
    }
    sort(p + 1, p + N + 1, comp);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &freq[i].f);
        freq[i].s = i;
    }
    sort(freq + 1, freq + N + 1, comp);
    for (int i = 1; i <= N; i++) {
        freq[i].f += freq[i - 1].f;
    }
    sort(key + 1, key + N + 1);

    FILL(dp, -1);
    printf("%d\n", min(solve(1, N, 0), solve(1, N, 1)));
    
    return 0;
}
