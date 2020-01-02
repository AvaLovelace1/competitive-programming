/*
 Solution to New Year Permutations by Ava Pun
 Key concepts: combinatorics, dynamic programming, disjoint set
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
const int MAX = 2e5 + 5;
const double EPS = 1e-9;
const ll INFK = 2e18;

int T, N;
ll K;
ll dp[55], fact[55];
int ans[55], par[55], rnk[55];
bool used[55];

inline ll mult(ll a, ll b) {
    long double ret = (long double) a * b;
    return ret >= INFK ? INFK : a * b;
}

inline ll add(ll a, ll b) {
    return min(INFK, a + b);
}

inline ll cycleCnt(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return fact[x - 2];
    }
}

int Find(int x) {
    if (x != par[x]) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

inline bool connected(int a, int b) {
    return Find(a) == Find(b);
}

inline bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return 0;
    }
    if (rnk[a] < rnk[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (rnk[a] == rnk[b]) {
            rnk[a]++;
        }
    }
    return 1;
}

inline void solve(int N, ll K) {
    if (K > dp[N]) {
        printf("-1\n");
        return;
    }

    FILL(used, 0);
    FILL(ans, 0);
    FILL(rnk, 0);
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }

    int i = 1;
    while (i <= N) {
        int n = N - i + 1;
        for (int m = 1; m <= n; m++) {
            ll tot = mult(cycleCnt(m), dp[n - m]);
            if (K > tot) {
                K -= tot;
            } else {
                int largest = i + m - 1;
                ans[i] = largest;
                for (int j = i + 1; j <= largest; j++) {
                    int rem = largest - j;
                    for (int x = i; x < largest; x++) {
                        if (!used[x]) {
                            if (j == largest) {
                                ans[j] = x;
                                break;
                            } else if (j != largest && !connected(j, x)) {
                                tot = mult(fact[rem - 1], dp[n - m]);
                                if (K > tot) {
                                    K -= tot;
                                } else {
                                    ans[j] = x;
                                    used[x] = 1;
                                    Union(j, x);
                                    break;
                                }
                            }
                        }
                    }
                }
                i = largest + 1;
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d", ans[i]);
        printf(i == N ? "\n" : " ");
    }
}

int main() {

    fact[0] = 1;
    for (int i = 1; i <= 50; i++) {
        fact[i] = mult(fact[i - 1], i);
    }

    dp[0] = 1;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = add(dp[i], mult(cycleCnt(j), dp[i - j]));
        }
    }

    scanf("%d", &T);

    while (T--) {
        scanf("%d%lld", &N, &K);
        solve(N, K);
    }

    return 0;
}
