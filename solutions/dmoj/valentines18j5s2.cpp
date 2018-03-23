/*
 Solution to Valentine's Day '18 J5 & S2 - Ctudor's Cute Orchids by Ava Pun
 Key concepts: bitmask brute force
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e4 + 5;

int N, M;
int cost[15], quan[15], tmp[15];
int deal[15][15];

int solve(int n) {
    fill(tmp, tmp + N + 1, 0);
    int sum = 0;
    for (int i = 1; i <= M; i++) {
        if (n & (1 << (i - 1))) {
            sum += deal[i][0];
            for (int j = 1; j <= N; j++) {
                tmp[j] += deal[i][j];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (tmp[i] > quan[i]) {
            return INF;
        }
        if (tmp[i] < quan[i]) {
            sum += cost[i] * (quan[i] - tmp[i]);
        }
    }
    return sum;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d", &deal[i][0]);
        for (int j = 1; j <= N; j++) {
            scanf("%d", &deal[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &quan[i]);
    }
    
    int ans = INF;
    for (int i = 0; i < 1 << M; i++) {
        ans = min(ans, solve(i));
    }
    
    printf("%d", ans);
    
    return 0;
}
