/*
 Solution to Cake Balancing by Ava Pun
 Key concepts: bitmask dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3F3F3F3F;

int L, R, W;
int wl[11], wr[11];
int dp[(1 << 10) + 1][(1 << 10) + 1];
vector<int> states[(1 << 10) + 1];
int sumsL[(1 << 10) + 1], sumsR[(1 << 10) + 1];

int sum(int s, int n, int arr[], int sums[]) {
    if (sums[s] == -1) {
        if (!s) {
            sums[s] = 0;
        } else {
            int idx = __builtin_ffs(s) - 1;
            sums[s] = sum(s & ~(1 << idx), n, arr, sums) + arr[idx];
        }
    }
    return sums[s];
}

int solve(int l, int r) {
    
    if (dp[l][r] == -1) {
        if (l == 0 && r == 0) {
            return 0;
        } else {
            dp[l][r] = INF;
            int ls = sum(l, L, wl, sumsL);
            int rs = sum(r, R, wr, sumsR);
            for (int i : states[l]) {
                if (abs(ls - sum(i, L, wl, sumsL) - rs) <= W) {
                    dp[l][r] = min(dp[l][r], solve(l & ~i, r) + 1);
                }
            }
            for (int i : states[r]) {
                if (abs(rs - sum(i, R, wr, sumsR) - ls) <= W) {
                    dp[l][r] = min(dp[l][r], solve(l, r & ~i) + 1);
                }
            }
        }
    }
    return dp[l][r];
    
}

int main() {
    
    scanf("%d%d%d", &L, &R, &W);
    for (int i = 0; i < L; i++) {
        scanf("%d", &wl[i]);
    }
    for (int i = 0; i < R; i++) {
        scanf("%d", &wr[i]);
    }
    
    for (int i = 1; i < (1 << max(L, R)); i++) {
        for (int j = 1; j <= i; j++) {
            if (!(~i & j)) {
                states[i].push_back(j);
            }
        }
    }
    
    fill(sumsL, sumsL + (1 << L) + 1, -1);
    fill(sumsR, sumsR + (1 << R) + 1, -1);
    memset(dp, -1, sizeof(dp));
    printf("%d", solve((1 << L) - 1, (1 << R) - 1));
    
    return 0;
}
