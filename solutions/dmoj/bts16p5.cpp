/*
 Solution to Back to School '16: Cherry Tree by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e4 + 5;

int N, C, K;
int arr[MAX];
vii adj[MAX];
int weight[2][MAX];

int solve(int u, int p) {
    int ans = 0;
    weight[0][u] = arr[u];
    for (auto e : adj[u]) {
        int v = e.f, w = e.s;
        if (v != p) {
            ans += solve(v, u);
            weight[0][u] += weight[0][v];
            weight[1][u] += weight[1][v] + w;
            ans += weight[0][v] >= C && weight[1][v] + w <= K;
        }
    }
    return ans;
}

int main() {

    scanf("%d%d%d", &N, &C, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    int a, b, d;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d%d%d", &a, &b, &d);
        adj[a].pb({b, d});
        adj[b].pb({a, d});
    }
    printf("%d\n", solve(1, -1));

    return 0;
}
