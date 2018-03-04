/*
 Solution to CCO '17 P4 - Rainfall Storage by Ava Pun
 Key concepts: knapsack dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 505;

int N;
int arr[MAX];
bool dp[2][500 * 50 + 5];
unordered_set<int> vis;
int maxN;

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N, greater<int>());
    maxN = N * arr[0];
    
    dp[0][0] = 1;
    vis.insert(arr[1]);
    for (int i = 2; i < N; i++) {
        vis.insert(arr[i]);
        for (int j : vis) {
            for (int k = j - arr[i]; k <= maxN; k++) {
                if (dp[0][k - (j - arr[i])]) {
                    dp[1][k] = 1;
                }
            }
        }
        for (int k = 0; k <= maxN; k++) {
            dp[0][k] = dp[1][k];
            dp[1][k] = 0;
        }
    }
    
    for (int i = 0; i <= maxN; i++) {
        if (dp[0][i]) {
            printf("%d ", i);
        }
    }
    
    return 0;
}
