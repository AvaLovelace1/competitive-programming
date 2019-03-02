/*
 Solution to DMPG '15 G5 - ExpedColle by Ava Pun
 Key concepts: knapsack dynamic programming
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
const int MAX = 2005;

int N, R, E;
ll C, V, CA, CB, CM, VA, VB, VM;
priority_queue<int, vector<int>, greater<int>> pq[MAX];
ll dp[MAX];

int main() {
    
    scanf("%d%d", &N, &R);
    ll zeros = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d%lld%lld", &E, &C, &V);
        scanf("%lld%lld%lld", &CA, &CB, &CM);
        scanf("%lld%lld%lld", &VA, &VB, &VM);
        for (int j = 1; j <= E; j++) {
            if (C == 0) {
                zeros += V;
            } else if (C <= R) {
                if (pq[C].size() < R / C) {
                    pq[C].push((int) V);
                } else if (pq[C].top() < V) {
                    pq[C].pop();
                    pq[C].push((int) V);
                }
            }
            C = (C * CA % CM + CB) % CM;
            V = (V * VA % VM + VB) % VM;
        }
    }

    for (int i = 1; i <= R; i++) {
        while (!pq[i].empty()) {
            int v = pq[i].top();
            pq[i].pop();
            for (int j = R; j >= i; j--) {
                if (j - i >= 0) {
                    dp[j] = max(dp[j], dp[j - i] + v);
                }
            }
        }
    }
    printf("%lld\n", dp[R] + zeros);

    return 0;
}
