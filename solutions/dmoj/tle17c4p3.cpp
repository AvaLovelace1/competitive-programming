/*
 Solution to TLE '17 Contest 4 P3 - Fax's Christmas Dish by Ava Pun
 Key concepts: graph theory
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M, D;
vector<int> adj[300001];
int arr[300001];

int dfs(int n) {
    int needed;
    if (!adj[n].empty()) {
        needed = -1;
        for (int i : adj[n]) {
            needed = max(needed, dfs(i));
        }
        needed = min(needed, arr[n]);
    } else {
        needed = arr[n];
    }
    return needed;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &D);
    
    int t, n, x;
    while (M--) {
        scanf("%d%d", &t, &n);
        while (n--) {
            scanf("%d", &x);
            adj[t].push_back(x);
        }
    }
    
    fill(arr, arr + N + 1, INT_MAX);
    
    for (int i = 1; i <= D; i++) {
        scanf("%d", &n);
        if (arr[n] == INT_MAX) {
            arr[n] = i;
        }
    }
    
    int ans = dfs(1);
    
    printf("%d", ans == INT_MAX ? -1 : ans);
    
    return 0;
    
}
