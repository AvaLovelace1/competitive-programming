/*
 Solution to The Polar Express by Ava Pun
 Key concepts: digit dynamic programming
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
const int MAX = 2e5 + 5;

ll L, R;
ll dp[20][165];
int digits[20];

ll solve(int d, int k, bool t) {
    
    if (k < 0) {
        return 0;
    }
    if (d == 0) {
        return k == 0;
    }
    if (!t && dp[d][k] != -1) {
        return dp[d][k];
    }
    
    int bound = t ? digits[d] : 9;
    ll ans = 0;
    for (int i = 0; i <= bound; i++) {
        ans += solve(d - 1, k - i, t && (digits[d] == i));
    }
    if (!t) {
        dp[d][k] = ans;
    }
    
    return ans;
}

ll solve(ll N, int k) {
    ll n = N;
    int cnt = 0;
    while (n) {
        digits[++cnt] = n % 10;
        n /= 10;
    }
    return solve(cnt, k, 1);
}

int main() {
    
    FILL(dp, -1);
    scanf("%lld%lld", &L, &R);
    int ans = 0;
    for (int i = 1; i <= 162; i++) {
        ans += solve(R, i) > solve(L - 1, i);
    }
    printf("%d\n", ans);
    
    return 0;
}
