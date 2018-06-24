/*
 Solution to CCO '18 P5 - Boring Lectures by Ava Pun
 Key concepts: segment tree
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

int N, K, Q;
pii maxTree[2 * MAX];
int locTree[2 * MAX];

void update(int pos, int x, pii tree[]) {
    pos += N - 1;
    tree[pos].f = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

void update(int pos, int x, int tree[]) {
    pos += N - 1;
    tree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

pii query(int l, int r, pii tree[]) {
    l = max(l, 1), r = min(r, N);
    l += N - 1, r += N - 1;
    pii ans = {-1, -1};
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

void checkLoc(int i) {
    int val = maxTree[i + N - 1].f;
    int maxL = query(i - K + 1, i - 1, maxTree).f, maxR = query(i + 1, i + K - 1, maxTree).f;
    if (val >= maxL && val > maxR) {
        locTree[i + N - 1] = val + max(maxL, maxR);
    } else {
        locTree[i + N - 1] = -1;
    }
}

void checkLoc1(int i) {
    checkLoc(i), update(i, locTree[i + N - 1], locTree);
}

int main() {
    
    scanf("%d%d%d", &N, &K, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &maxTree[i + N - 1].f);
    }
    for (int i = 1; i <= N; i++) {
        maxTree[i + N - 1].s = i;
    }
    for (int i = N - 1; i > 0; i--) {
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1]);
    }
    for (int i = 1; i <= N; i++) {
        checkLoc(i);
    }
    for (int i = N - 1; i > 0; i--) {
        locTree[i] = max(locTree[i << 1], locTree[i << 1 | 1]);
    }
    
    int ans = locTree[1];
    printf("%d\n", ans);
    
    int i, x;
    while (Q--) {
        scanf("%d%d", &i, &x);
        //i ^= ans, x ^= ans;
        update(i, x, maxTree);
        checkLoc1(i);
        int maxL = query(i - K + 1, i - 1, maxTree).s, maxR = query(i + 1, i + K - 1, maxTree).s;
        checkLoc1(maxL), checkLoc1(maxR);
        ans = locTree[1];
        printf("%d\n", ans);
    }
    
    return 0;
}
