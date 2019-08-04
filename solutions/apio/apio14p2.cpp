/*
 Solution to APIO '14 P2 - Split the Sequence by Ava Pun
 Key concepts: dynamic programming, convex hull optimization
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int N, K;
int arr[MAX];
ll dp[2][MAX];
int trace[205][MAX];
piii q[MAX];
int path[MAX];

inline ll cost(pii p, int x) {
    return p.f * x + p.s;
}

inline ll intersect(pii a, pii b) {
    if (a.f == b.f) {
        return a.s > b.s ? INFL : -INFL;
    }
    return (b.s - a.s + (a.f - b.f - 1)) / (a.f - b.f);
}

int main() {

    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    
    for (int i = 1; i <= K; i++) {
        int fIdx = 0, bIdx = 0;
        for (int j = 0; j <= N; j++) {
            int x = arr[j];
            while (fIdx + 1 < bIdx && cost(q[fIdx].s, x) <= cost(q[fIdx + 1].s, x)) {
                fIdx++;
            }
            if (fIdx < bIdx) {
                dp[i & 1][j] = cost(q[fIdx].s, x);
                trace[i][j] = q[fIdx].f;
            } else {
                dp[i & 1][j] = 0;
            }
            pii nxt = {x, dp[!(i & 1)][j] - (ll) x * x};
            while (fIdx + 1 < bIdx && intersect(q[bIdx - 2].s, q[bIdx - 1].s) >= intersect(q[bIdx - 1].s, nxt)) {
                bIdx--;
            }
            q[bIdx++] = {j, nxt};
        }
    }
    printf("%lld\n", dp[K & 1][N]);
    int u = N;
    for (int i = K; i >= 1; i--) {
        path[i] = trace[i][u];
        u = trace[i][u];
    }
    for (int i = 1; i <= K; i++) {
        printf("%d", path[i]);
        printf(i == K ? "\n" : " ");
    }

    return 0;
}
