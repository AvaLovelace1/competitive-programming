/*
 Solution to We Love ABC by Ava Pun
 Key concepts: prefix sum array, combinatorics
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, tot = 0;
string S;
ll pref[2][MAX], dp[2][MAX], power[MAX];

inline ll query(int l, int r, ll pref[]) {
    return (pref[r] - pref[l - 1] + MOD) % MOD;
}

inline ll pow3(int n) {
    if (n < 0) {
        return 0;
    } else {
        return power[n];
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    N = (int) S.length();
    S = ' ' + S;
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = power[i - 1] * 3 % MOD;
        if (S[i] == 'C') {
            pref[0][i] = 1;
        } else if (S[i] == '?') {
            tot++;
            pref[1][i] = 1;
        }
        pref[0][i] += pref[0][i - 1];
        pref[1][i] += pref[1][i - 1];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1; j++) {
            if (S[i] == 'B') {
                dp[j][i] = (query(i + 1, N, pref[0]) * pow3(tot - j) % MOD
                            + query(i + 1, N, pref[1]) * pow3(tot - 1 - j) % MOD) % MOD;
            } else if (S[i] == '?') {
                dp[j][i] = (query(i + 1, N, pref[0]) * pow3(tot - 1 - j) % MOD
                            + query(i + 1, N, pref[1]) * pow3(tot - 2 - j) % MOD) % MOD;
            }
            dp[j][i] += dp[j][i - 1];
            dp[j][i] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (S[i] == 'A') {
            ans += query(i + 1, N, dp[0]);
            ans %= MOD;
        } else if (S[i] == '?') {
            ans += query(i + 1, N, dp[1]);
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
