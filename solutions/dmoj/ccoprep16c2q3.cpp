/*
 Solution to HopScotch by Ava Pun
 Key concepts: square root query bucketing
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
const int MAX = 2e5 + 5;

int N, Q;
int BLOCK_SIZE;
int arr[MAX];
pii quers[100005];
int blockCnt = 0;
int block[MAX];
int dp[MAX], lnk[MAX];

inline int solve(int x) {
    int ans = 0;
    while (x <= N) {
        ans += dp[x] + 1;
        x = lnk[x] + arr[lnk[x]];
    }
    return ans;
}

int main() {
        
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }  
    scanf("%d", &Q);
    BLOCK_SIZE = sqrt(Q);
    int t;
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &quers[i].f);
            quers[i].f++;
            quers[i].s = -1;
        } else {
            scanf("%d%d", &quers[i].f, &quers[i].s);
            quers[i].f++;
        }
    }
    
    for (int l = 1; l <= Q; l += BLOCK_SIZE) {
        int r = min(Q, l + BLOCK_SIZE - 1);
        blockCnt++;
        for (int i = l; i <= r; i++) {
            if (quers[i].s != -1) {
                block[quers[i].f] = blockCnt;
            }
        }
        for (int i = N; i >= 1; i--) {
            if (block[i] == blockCnt || i + arr[i] > N) {
                dp[i] = 0;
                lnk[i] = i;
            } else {
                dp[i] = dp[i + arr[i]] + 1;
                lnk[i] = lnk[i + arr[i]];
            }
        }
        for (int i = l; i <= r; i++) {
            if (quers[i].s != -1) {
                arr[quers[i].f] = quers[i].s;
            } else {
                printf("%d\n", solve(quers[i].f));
            }
        }
    }

    return 0;
}
