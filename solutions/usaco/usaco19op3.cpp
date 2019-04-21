/*
 Solution to USACO '19 Open P3 - Valleys by Ava Pun
 Key concepts: disjoint set
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 755;

const pii dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const pii ptwise[] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int N;
int arr[MAX][MAX];
int events[1000005];
int par[MAX * MAX], sz[MAX * MAX], curve[MAX * MAX], rnk[MAX * MAX];

inline int conv(int r, int c) {
    return r * (N + 2) + c;
}

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

inline bool same(int a, int b) {
    return Find(a) == Find(b);
}

inline int corner(int a, int b, int c) {
    if (a + b + c == 0) {
        return 1;
    } else if (a + b + c == 1) {
        return b == 1 ? 1 : -1;
    } else if (a + b + c == 2) {
        return b == 0 ? -3 : -1;
    } else {
        return 1;
    }
}

inline bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return 0;
    }
    if (rnk[a] < rnk[b]) {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
    curve[a] += curve[b];
    if (rnk[a] == rnk[b]) {
        rnk[a]++;
    }
}

int main() {

    freopen("valleys.in", "r", stdin);
    freopen("valleys.out", "w", stdout);
    
    FILL(arr, INF);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
            events[arr[i][j]] = {conv(i, j)};
        }
    }
    for (int i = 0; i < (N + 2) * (N + 2); i++) {
        par[i] = i, sz[i] = 1;
    }

    ll ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (events[i] != 0) {
            int e = events[i];
            int r = e / (N + 2), c = e % (N + 2);
            for (pii p : dirs) {
                if (arr[r + p.f][c + p.s] < arr[r][c]) {
                    Union(e, conv(r + p.f, c + p.s));
                }
            }
            for (int i = 0; i < 8; i += 2) {
                curve[Find(e)] += corner(same(conv(r + ptwise[i].f, c + ptwise[i].s), e),
                        same(conv(r + ptwise[(i + 1) % 8].f, c + ptwise[(i + 1) % 8].s), e),
                        same(conv(r + ptwise[(i + 2) % 8].f, c + ptwise[(i + 2) % 8].s), e));
            }
            if (curve[Find(e)] == 4) {
                ans += sz[Find(e)];
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
