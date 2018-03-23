/*
 Solution to Valentine's Day '18 S4 - Coastal California Cities by Ava Pun
 Key concepts: dynamic programming on trees
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 200005;

int N;
vector<int> adj[MAX];
ll num[MAX];

ll fact(int n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

ll solve(int n) {
    if (num[n] == -1) {
        num[n] = 1;
        for (int c : adj[n]) {
            num[n] = num[n] * solve(c) % MOD;
        }
        num[n] = num[n] * fact((int) adj[n].size()) % MOD * (adj[n].size() + 1) % MOD;
        if (adj[n].empty()) {
            num[n] = 1;
        }
    }
    return num[n];
}

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i < N; i++) {
        scanf("%d", &n);
        adj[n].push_back(i);
    }
    
    fill(num, num + N, -1);
    
    printf("%lld", solve(0));
    
    return 0;
}
