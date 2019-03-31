/*
 Solution to Pick it II by Ava Pun
 Key concepts: dynamic programming, segment tree
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
const int MAX = 1e5 + 10;

int N, K;
ll arr[MAX];
ll dp[MAX], tree[2 * MAX];

inline void upd(int pos, ll x) {
    pos += N;
    tree[pos] += x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

inline ll quer(int l, int r) {
    l = max(l, 0), r = min(r, N - 1);
    l += N, r += N;
    ll ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = max(ans, tree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = N; i >= 0; i--) {
        arr[i] += arr[i + 1];
    }
    N += 2;
    for (int i = 1; i <= N - 2; i++) {
        tree[i + N - 1] = arr[i];
    }
    for (int i = N - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
    
    for (int i = 1; i <= N - 1; i++) {
        dp[i] = quer(i - K - 1, i - 1) - arr[i];
        upd(i, dp[i]);
    }
    printf("%lld\n", dp[N - 1]);
    
    return 0;
}
