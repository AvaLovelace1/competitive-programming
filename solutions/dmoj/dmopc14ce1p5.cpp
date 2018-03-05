/*
 Solution to DMOPC '14 Exam Time P5 - Happy Teachers by Ava Pun
 Key concepts: knapsack dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, S;
int H[51], E[51], P[51];
pii dp[51][101][1001];

bool comp(pii a, pii b) {
    if (a.first == b.first) {
        return a > b;
    } else {
        return a < b;
    }
}

pii solve(int i, int j, int k) {

    if (i >= N) {
        return {0, 0};
    } else if (j >= H[i]) {
        return solve(i + 1, 0, k);
    }
    
    if (dp[i][j][k].first == -1) {
        if (k < P[i]) {
            dp[i][j][k] = solve(i + 1, 0, k);
        } else {
            pii take = solve(i, j + E[i], k - P[i]);
            take.first += max(H[i] - j, 0);
            take.second++;
            pii leave = solve(i + 1, 0, k);
            dp[i][j][k] = max(take, leave, comp);
        }
    }
    return dp[i][j][k];
    
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &H[i], &E[i], &P[i]);
    }
    scanf("%d", &S);
    
    memset(dp, -1, sizeof(dp));
    pii ans = solve(0, 0, S);
    
    printf("%d\n%d", ans.first, ans.second);
    
    return 0;
}
