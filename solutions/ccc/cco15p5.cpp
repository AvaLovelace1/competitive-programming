/*
 Solution to CCO '15 P5 - Timpanist by Ava Pun
 Key concepts: bitmask dynamic programming, BFS
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
const int MAX = 2005;
const double EPS = 1e-9;

int N, D;
pii arr[105];
vi states;
int dist[500][500];
bool done[105][500];
double dp[105][500];

inline int getIdx(int x) {
    return (int) (lower_bound(states.begin(), states.end(), x) - states.begin());
}

void gen(int n, int d, int x) {
    if (d == 0) {
        states.pb(x);
        return;
    }
    for (int i = n; i < 12 - d + 1; i++) {
        gen(i + 1, d - 1, x | (1 << i));
    }
}

inline void bfs(int S) {
    queue<int> q;
    q.push(S);
    dist[S][S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 12; i++) {
            if (states[u] & (1 << i)) {
                for (int j = i + 1; j < 12 && !(states[u] & (1 << j)); j++) {
                    int v = getIdx((states[u] & ~(1 << i)) | (1 << j));
                    if (dist[S][v] == INF) {
                        dist[S][v] = dist[S][u] + 1;
                        q.push(v);
                    }
                }
                for (int j = i - 1; j >= 0 && !(states[u] & (1 << j)); j--) {
                    int v = getIdx((states[u] & ~(1 << i)) | (1 << j));
                    if (dist[S][v] == INF) {
                        dist[S][v] = dist[S][u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
}

double solve(int n, int m) {
    double &ret = dp[n][m];
    if (!done[n][m]) {
        if (n >= N) {
            ret = INF;
        } else {
            dp[n][m] = 0;
            for (int i = 0; i < states.size(); i++) {
                if (states[i] & (1 << arr[n].s)) {
                    dp[n][m] = max(dp[n][m], min(solve(n + 1, i), (double) (arr[n].f - arr[n - 1].f) / dist[m][i]));
                }
            }
        }
        done[n][m] = 1;
    }
    return ret;
}

int main() {

    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
        arr[i].s--;
    }
    gen(0, D, 0);
    sort(states.begin(), states.end());

    FILL(dist, INF);
    for (int i = 0; i < states.size(); i++) {
        bfs(i);
    }

    double ans = 0;
    for (int i = 0; i < states.size(); i++) {
        if (states[i] & (1 << arr[0].s)) {
            ans = max(ans, solve(1, i));
        }
    }
    printf("%.2lf\n", ans == INF ? 0 : ans);

    return 0;
}
