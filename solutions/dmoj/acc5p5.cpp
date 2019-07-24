/*
 Solution to Another Contest 5 Problem 5 - Another Cheese Problem by Ava Pun
 Key concepts: greedy algorithms, dynamic programming on trees
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
const int MAX = 1e6 + 5;

int N;
int arr[MAX];
vi adj[MAX];
int dp[MAX];

void solve(int u) {
    vi answers;
    for (int v : adj[u]) {
        solve(v);
        answers.pb(dp[v]);
    }
    sort(answers.begin(), answers.end(), greater<int>());
    dp[u] = 0;
    for (int i = 0; i < answers.size(); i++) {
        dp[u] = max(dp[u], answers[i] + i);
    }
    dp[u] = max(dp[u], (int) adj[u].size() + 1);
    answers.clear();
}

int main() {
    
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        scanf("%d", &arr[i]);
        adj[arr[i]].pb(i);
    }
    solve(1);
    printf("%d\n", dp[1]);
    
    return 0;
}
