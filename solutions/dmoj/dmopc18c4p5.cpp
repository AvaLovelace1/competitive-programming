/*
 Solution to DMOPC '18 Contest 4 P5 - Dr. Henri and Wormholes by Ava Pun
 Key concepts: dynamic programming on trees
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

int N, K;
bool twice[MAX];
int weight[MAX];
vii adj[MAX];
int dp[MAX][3];
/*
 dp[i][j] is the length of the longest path through i in case j
 j = 3 cases:
 0 - path starts and ends in i (must be a closed path)
 1 - path ends in i (can be open at one end)
 2 - path starts and ends in two (not necessarily distinct) subtrees of i (can be open at both ends)
 */

void solve(int u, int prev) {
    
    int ret = 0;
    int max1[2] = {0, 0}; // 2 greatest positive differences between closed path and singly open path of a subtree
    int max2 = 0; // greatest positive difference between closed path and doubly open path of a subtree
    
    for (auto e : adj[u]) {
        int v = e.f, w = weight[e.s];
        if (v != prev) {
            solve(v, u);
            int val[3] = { // longeat path through subtree v...
                twice[e.s] ? dp[v][0] + 2 * w : 0, // ...starting and ending in u
                max(dp[v][0], dp[v][1]) + w, // ...ending in u
                twice[e.s] ? max(dp[v][0], max(dp[v][1], dp[v][2])) + 2 * w : 0 // ...starting and ending in subtree v
                };
            ret += val[0];
            int diff = val[1] - val[0];
            if (diff >= max1[0]) {
                max1[1] = max1[0];
                max1[0] = diff;
            } else if (diff > max1[1]) {
                max1[1] = diff;
            }
            max2 = max(max2, val[2] - val[0]);
        }
    }
    
    dp[u][0] = ret; // case 0: sum of all paths through subtrees starting and ending in u
    dp[u][1] = ret + max1[0]; // case 1: replace 1 closed path with singly open path
    dp[u][2] = max(ret + max1[0] + max1[1], ret + max2); // case 2: replace 2 closed paths, or replace 1 closed path with a doubly open path
}

int main() {
    
    scanf("%d%d", &N, &K);
    int a, b, d;
    for (int i = 1; i <= K; i++) {
        scanf("%d", &d);
        twice[d] = 1;
    }
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d%d", &a, &b, &d);
        weight[i] = d;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
    }

    solve(1, -1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
