/*
 Solution to IOI '15 P4 - Horses by Ava Pun
 Key concepts: segment tree with lazy propagation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<double, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

int N, Q, H;
int grow[MAX], sell[MAX];
ll modTree[2 * MAX];
double lazy[MAX];
pii maxTree[2 * MAX];

inline void updMod(int pos, int x) {
    pos += N;
    modTree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        modTree[i] = modTree[i << 1] * modTree[i << 1 | 1] % MOD;
    }
}

ll queryMod(int l, int r) {
    l += N, r += N;
    ll ans = 1;
    while (l <= r) {
        if (l & 1) {
            ans = ans * modTree[l] % MOD;
            l++;
        }
        if (!(r & 1)) {
            ans = ans * modTree[r] % MOD;
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

inline void apply(int pos, double x) {
    maxTree[pos].f += x;
    if (pos < N) {
        lazy[pos] += x;
    }
}

inline void down(int pos) {
    for (int k = H; k > 0; k--) {
        int i = pos >> k;
        if (lazy[i]) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

inline void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1]);
        maxTree[i].f += lazy[i];
    }
}

void updMax(int l, int r, double x) {
    l += N, r += N;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l & 1) {
            apply(l, x);
            l++;
        }
        if (!(r & 1)) {
            apply(r, x);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    up(l0), up(r0);
}

inline int getMax() {
    return queryMod(0, maxTree[1].s) * sell[maxTree[1].s] % MOD; 
}

int updateX(int pos, int val) {
    updMod(pos, val);
    updMax(pos, N - 1, log2((double) val / grow[pos]));
    grow[pos] = val;
    return getMax();
}

int updateY(int pos, int val) {
    updMax(pos, pos, log2((double) val / sell[pos]));
    sell[pos] = val;
    return getMax();
}

int init(int n, int X[], int Y[]) {
    N = n;
    H = sizeof(int) * 8 - __builtin_clz(N);
    for (int i = 0; i < N; i++) {
        grow[i] = X[i], sell[i] = Y[i];
        modTree[i + N] = X[i];
    }
    for (int i = N - 1; i > 0; i--) {
        modTree[i] = modTree[i << 1] * modTree[i << 1 | 1] % MOD;
    }
    double curr = 0;
    for (int i = 0; i < N; i++) {
        curr += log2(grow[i]);
        maxTree[i + N] = {log2(sell[i]) + curr, i};
    }
    for (int i = N - 1; i > 0; i--) {
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1]);
    }
    return getMax();
}

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &grow[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &sell[i]);
    }
    printf("%d\n", init(N, grow, sell));
    scanf("%d", &Q);
    int t, pos, val;
    while (Q--) {
        scanf("%d%d%d", &t, &pos, &val);
        if (t == 1) {
            printf("%d\n", updateX(pos, val));
        } else {
            printf("%d\n", updateY(pos, val));
        }
    }
    
    return 0;
}
