/*
 Solution to USACO '18 January S2 - Rental Service by Ava Pun
 Key concepts: greedy algorithms
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, bool> piii;
const int INF = 0x3F3F3F3F;
const int MAX = 1e5 + 1;

int N, M, R;
int milk[MAX];
ll rent[MAX];
ll worth[MAX];
pii stores[MAX];

int main() {
    
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    
    scanf("%d%d%d", &N, &M, &R);
    for (int i = 0; i < N; i++) {
        scanf("%d", &milk[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &stores[i].second, &stores[i].first);
    }
    for (int i = 0; i < R; i++) {
        scanf("%lld", &rent[i]);
    }
    
    sort(milk, milk + N, greater<int>());
    sort(stores, stores + M, greater<pii>());
    sort(rent, rent + R, greater<int>());
    
    int s = 0;
    for (int i = 0; i < N && s < M; i++) {
        while (milk[i] > 0 && s < M) {
            int m = min(milk[i], stores[s].second);
            worth[i] += (ll) m * stores[s].first;
            milk[i] -= m, stores[s].second -= m;
            if (stores[s].second == 0) {
                s++;
            }
        }
    }
    
    int r = 0;
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans += max(worth[i], rent[r]);
        r++;
    }
    
    printf("%lld", ans);
    
    return 0;
}
