/*
 Solution to COI '07 #4 Umnozak by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1005;

ll A, B;
const int primes[] = {2, 3, 5, 7};
const int facts[][4] = {
    {0, 0, 0, 0}, {0, 0, 0, 0},
    {1, 0, 0, 0}, {0, 1, 0, 0},
    {2, 0, 0, 0}, {0, 0, 1, 0},
    {1, 1, 0, 0}, {0, 0, 0, 1},
    {3, 0, 0, 0}, {0, 2, 0, 0} };
int k[4];
ll dp[20][30][19][13][11][2];
int digits[20];

ll solve(int d, bool t, bool st) {
    
    for (int i = 0; i < 4; i++) {
        if (k[i] < 0) {
            return 0;
        }
    }
    if (d == 0) {
        for (int i = 0; i < 4; i++) {
            if (k[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
    if (!t && dp[d][k[0]][k[1]][k[2]][k[3]][st] != -1) {
        return dp[d][k[0]][k[1]][k[2]][k[3]][st];
    }
    
    ll ans = 0;
    int bound = t ? digits[d] : 9;
    for (int i = st; i <= bound; i++) {
        for (int j = 0; j < 4; j++) {
            k[j] -= facts[i][j];
        }
        ans += solve(d - 1, t && (i == digits[d]), i != 0);
        for (int j = 0; j < 4; j++) {
            k[j] += facts[i][j];
        }
    }
    if (!t) {
        dp[d][k[0]][k[1]][k[2]][k[3]][st] = ans;
    }
    
    return ans;
}

ll solve(ll N) {
    ll n = N;
    int cnt = 0;
    while (n) {
        digits[++cnt] = n % 10;
        n /= 10;
    }
    return solve(cnt, 1, 0);
}

ll gen(ll n, int cnt) {
    if (n > 1e9 || n * n > B) {
        return 0;
    }
    if (cnt == 4) {
        return solve(B / n) - solve(ceil((double) A / n) - 1);
    }
    ll ans = 0;
    ans += gen(n, cnt + 1);
    k[cnt]++;
    ans += gen(n * primes[cnt], cnt);
    k[cnt]--;
    return ans;
}

int main() {
    
    FILL(dp, -1);
    scanf("%lld%lld", &A, &B);
    printf("%lld\n", gen(1, 0));
    
    return 0;
}
