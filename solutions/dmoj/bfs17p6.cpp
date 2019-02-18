/*
 Solution to Back From Summer '17 P6: Crowded Cities by Ava Pun
 Key concepts: dynamic progrmaming, longest increasing subsequence, 2D binary indexed tree
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
const int MAX = 1e5 + 5;

struct block {
    int l, w, h, p, id;
    block(int l0, int w0, int h0, int p0, int id0) {
        l = l0, w = w0, h = h0, p = p0, id = id0;
    }
};

inline bool compBlock(block *a, block *b) {
    piii aa = {a->h, {a->l, a->w}};
    piii bb = {b->h, {b->l, b->w}};
    return aa < bb;
}

int N;
block *arr[MAX];
ll dp[MAX];
int trace[MAX];
int bit[5001][5001];

inline bool comp(int a, int b) {
    return dp[a] < dp[b];
}

inline void upd(int x, int y, int val) {
    for (int i = x; i <= 5000; i += i & -i) {
        for (int j = y; j <= 5000; j += j & -j) {
            bit[i][j] = max(bit[i][j], val, comp);
        }
    }
}

inline int quer(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            ans = max(ans, bit[i][j], comp);
        }
    }
    return ans;
}

int main() {
    
    scanf("%d", &N);
    int l, w, h, p;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d%d", &l, &w, &h, &p);
        if (l < w) {
            swap(l, w);
        }
        arr[i] = new block(l, w, h, p, i);
    }
    sort(arr + 1, arr + N + 1, compBlock);
    
    for (int i = 1; i <= N; i++) {
        int pre = quer(arr[i]->l, arr[i]->w);
        dp[i] = dp[pre] + arr[i]->p;
        trace[i] = pre;
        upd(arr[i]->l, arr[i]->w, i);
    }

    int u = (int) (max_element(dp + 1, dp + N + 1) - dp);
    printf("%lld\n", dp[u]);
    vi ans;
    while (u != 0) {
        ans.pb(u);
        u = trace[u];
    }
    printf("%d\n", (int) ans.size());
    for (int i : ans) {
        printf("%d ", arr[i]->id);
    }
    
    return 0;
}
