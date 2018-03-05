/*
 Solution to COCI '15 Contest 2 #2 Geppetto by Ava Pun
 Key concepts: brute force, graph theory
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5005;

int N, M;
vector<int> adj[MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = 0;
    bool found = true;
    for (int i = 0; i < 1 << N; i++) {
        found = true;
        for (int j = 0; j < N && found; j++) {
            if (i & (1 << j)) {
                for (int k : adj[j + 1]) {
                    if (i & (1 << (k - 1))) {
                        found = false;
                        break;
                    }
                }
            }
        }
        if (found) {
            ans++;
        }
    }
    printf("%d", ans);
    
    return 0;
    
}
