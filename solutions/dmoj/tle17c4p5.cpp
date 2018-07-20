/*
 Solution to TLE '17 Contest 4 P5 - Pascal's Tree by Ava Pun
 Key concepts: math, segment tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, N1, M;
int spf[MAX], fcnt[MAX];
vi pf[MAX];
ll tree[4 * MAX], ans[MAX];

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ret = pow(a * a % M, b / 2);
        if (b & 1) {
            ret *= a;
            ret %= M;
        }
        return ret;
    }
}

inline void update(int pos, int x) {
    fcnt[pos] = x;
    tree[pos + N1 - 1] = modPow(pos, x);
    for (int i = (pos + N1 - 1) >> 1; i > 0; i >>= 1) {
        tree[i] = tree[i << 1] * tree[i << 1 | 1] % M;
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    N1 = pow(2, ceil(log2(N)));
    fill(tree, tree + 4 * N + 1, 1);
    
    for (int i = 2; i <= N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        int n = i;
        while (n > 1) {
            pf[i].pb(spf[n]);
            n /= spf[n];
        }
    }
    
    for (int i = 0; i <= N / 2; i++) {
        for (int j : pf[N - i + 1]) {
            update(j, fcnt[j] + 1);
        }
        for (int j : pf[i]) {
            update(j, fcnt[j] - 1);
        }
        ans[i] = tree[1];
        printf("%lld\n", ans[i]);
    }
    for (int i = !(N & 1); i <= N / 2; i++) {
        printf("%lld\n", ans[N / 2 - i]);
    }
    
    return 0;
}
