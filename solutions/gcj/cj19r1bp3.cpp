/*
 Solution to Google Code Jam '19 R1B P3 - Fair Fight by Ava Pun
 Key concepts: binary search, sparse table
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9;
const int MAX = 1e5 + 5;

int T, N, K;
int spt[2][MAX][18];

inline int quer(int l, int r, int idx) {
    if (r < l) {
        return -1;
    }
    int len = (int) log2(r - l + 1);
    return max(spt[idx][l][len], spt[idx][r - (1 << len) + 1][len]);
}

inline int bsup(int l0, int r0, int x, int idx) {
    int l = l0, r = r0 + 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (quer(l0, m, idx) > x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

inline int bsdown(int l0, int r0, int x, int idx) {
    int l = l0, r = r0 + 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (quer(m, r0, idx) <= x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l - 1;
}

int main() {

    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        
        scanf("%d%d", &N, &K);
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &spt[i][j][0]);
            }
            for (int k = 1; k <= 17; k++) {
                for (int j = 1; j <= N; j++) {
                    if (j + (1 << (k - 1)) <= N) {
                        spt[i][j][k] = max(spt[i][j][k - 1], spt[i][j + (1 << (k - 1))][k - 1]);
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            int x = spt[0][i][0];
            int l = bsdown(1, i - 1, x - 1, 0) + 1, r = bsup(i, N, x, 0) - 1;
            int dl1 = bsdown(l, i - 1, x - K - 1, 1), dr1 = bsup(i, r, x - K - 1, 1);
            int dl2 = bsdown(l, i - 1, x + K, 1) + 1, dr2 = bsup(i, r, x + K, 1) - 1;
            ans += (ll) (dl1 - dl2 + 1) * (dr1 - i) + (ll) (dr2 - dr1 + 1) * (i - dl1);
            ans += (ll) (dl1 - dl2 + 1) * (dr2 - dr1 + 1);
        }
        printf("Case #%d: %lld\n", test, ans);

    }

    return 0;
}
