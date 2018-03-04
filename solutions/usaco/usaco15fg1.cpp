/*
 Solution to USACO '15 February G1 - Cow Hopscotch by Ava Pun
 Key concepts: dynamic programming, binary indexed tree, index compression
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 755;

int R, C, K;
int arr[MAX][MAX];
int dp[MAX];
vector<int> bit[MAX * MAX], v[MAX * MAX];
int master[MAX];

int conv(int idx, int k) {
    return (int) (lower_bound(v[k].begin(), v[k].end(), idx) - v[k].begin());
}


void update(int k, int pos, int x) {
    for (int i = pos; i <= C; i += i & -i) {
        master[i] += x;
        master[i] %= MOD;
    }
    for (int i = conv(pos, k); i < bit[k].size(); i += i & -i) {
        bit[k][i] += x;
        bit[k][i] %= MOD;
    }
}

int query(int k, int pos) {
    int ans = 0;
    int pos0 = conv(pos, k);
    if (v[k][pos0] > pos) {
        pos0--;
    }
    for (int i = pos0; i > 0; i -= i & -i) {
        ans += bit[k][i];
        ans %= MOD;
    }
    return ans;
}

int queryM(int pos) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += master[i];
        ans %= MOD;
    }
    return ans;
}

int main() {
    
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    
    scanf("%d%d%d", &R, &C, &K);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) {
            if (v[arr[i][j]].empty()) {
                v[arr[i][j]].push_back(0);
            }
            if (v[arr[i][j]].back() < j) {
                v[arr[i][j]].push_back(j);
            }
        }
    }
    for (int i = 1; i <= K; i++) {
        bit[i].resize(v[i].size());
    }
    
    int ans = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == 1 && j == 1) {
                dp[j] = 1;
            } else {
                dp[j] += queryM(j - 1);
                dp[j] %= MOD;
                dp[j] -= query(arr[i][j], j - 1);
                dp[j] += MOD;
                dp[j] %= MOD;
            }
        }
        for (int j = 1; j <= C; j++) {
            update(arr[i][j], j, dp[j]);
            ans = dp[j];
            dp[j] = 0;
        }
        
    }
    
    printf("%d", ans);
    
    return 0;
    
}
