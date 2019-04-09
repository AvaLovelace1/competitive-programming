/*
 Solution to WC18 #4 - Farming Simulator by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 3005;

int N, H;
pii arr[MAX];
ll dp[MAX];

int main() {
    
    scanf("%d%d", &N, &H);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    arr[++N] = {H, 0};
    sort(arr + 1, arr + N + 1);
    
    FILL(dp, INFL);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        int maxWait = 0;
        for (int j = i; j >= 1; j--) {
            maxWait = max(maxWait, arr[j].s);
            dp[i] = min(dp[i], dp[j - 1] + max(maxWait, 2 * (arr[i].f - arr[j].f)));
        }
    }
    printf("%lld\n", dp[N] + H);
    
    return 0;
}
