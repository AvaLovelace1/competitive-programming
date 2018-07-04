/*
 Solution to UTS Open '15 #4 - Subway by Ava Pun
 Key concepts: dynamic programming, graph theory, math, difference array
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
const int MOD = 1e9 + 7;
const int MAX = 2005;

int N, M, T;
vector<piii> adj[MAX];
double dp[MAX][MAX];

int main() {
    
    scanf("%d%d%d", &N, &M, &T);
    int a, b, x, y;
    while (M--) {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        if (a != N) {
            adj[a].pb({b, {x, y}});
        }
    }
    
    dp[0][1] = 1;
    dp[1][1] = -1;
    for (int i = 0; i <= T; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != 0) {
                dp[i][j] += dp[i - 1][j];
            }
            for (piii e : adj[j]) {
                int v = e.f, w1 = e.s.f, w2 = e.s.s;
                double add = dp[i][j] / ((w2 - w1 + 1) * adj[j].size());
                if (i + w1 <= T) {
                    dp[i + w1][v] += add;
                    dp[min(i + w2, T) + 1][v] -= add;
                }
            }
        }
    }
    
    double totX = 0, totChance = 0;
    for (int i = 0; i <= T; i++) {
        totX += dp[i][N] * i;
        totChance += dp[i][N];
    }
    printf("%.10lf\n", totX / totChance);
    
    return 0;
}
