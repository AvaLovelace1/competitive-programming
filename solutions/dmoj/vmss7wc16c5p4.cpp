/*
 Solution to VM7WC '16 #5 Silver - Jayden Eats Chocolate by Ava Pun
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
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
int arr[3], dp[MAX];

int main() {
    
    scanf("%d%d%d%d", &N, &arr[0], &arr[1], &arr[2]);
    for (int i = 1; i <= N; i++) {
        dp[i] = -1;
        for (int j : arr) {
            if (i - j >= 0 && dp[i - j] != -1) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }
    printf("%d\n", dp[N]);
    
    return 0;
}
