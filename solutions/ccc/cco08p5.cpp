/*
 Solution to CCO '08 P5 - Candy by Ava Pun
 Key concepts: knapsack dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<bool, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, K0, K;
int k[105], c[105];
bool dp[(int) (5e6 + 5)];
queue<int> q;

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &k[i], &c[i]);
        K0 += k[i] * c[i];
    }
    K = K0 / 2;

    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int b = 0; b < c[i]; b++) {
            while (!q.empty()) {
                q.pop();
            }
            for (int a = 0; a * c[i] + b <= K; a++) {
                int j = a * c[i] + b;
                while (!q.empty() && q.front() < a - k[i]) {
                    q.pop();
                }
                if (dp[j]) {
                    q.push(a);
                }
                dp[j] |= !q.empty();
            }
        }
    }
    int ans = 0;
    for (int i = K; i >= 0; i--) {
        if (dp[i]) {
            ans = i;
            break;
        }
    }
    printf("%d\n", K0 - 2 * ans);
    
    return 0;
}
