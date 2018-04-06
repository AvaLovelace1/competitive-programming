/*
 Solution to TLE '16 Contest 8 P3 - Fool's Sequence by Ava Pun
 Key concepts: dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int T;
vector<ll> dp;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    dp.push_back(0);
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    
    ll num = 3;
    int cnt = 5;
    while (num < 1e15) {
        ll ans = dp[cnt - 2] + dp[cnt - 3];
        dp.push_back(ans);
        num += ans;
        cnt++;
    }
    
    for (int i = 1; i < dp.size(); i++) {
        dp[i] += dp[i - 1];
    }
    
    ll n;
    while (T--) {
        cin >> n;
        string s = "";
        int len = (int) (lower_bound(dp.begin(), dp.end(), n) - dp.begin());
        n = dp[len] - n + 1;
        while (len) {
            if (len == 2 || (len - 2 >= 0 && n <= dp[len - 2] - (len - 3 >= 0 ? dp[len - 3] : 0))) {
                s += "69";
                len -= 2;
            } else if (len - 3 >= 0) {
                if (len - 2 >= 0) {
                    n -= dp[len - 2] - (len - 3 >= 0 ? dp[len - 3] : 0);
                }
                s += "420";
                len -= 3;
            }
        }
        cout << s << "\n";
    }
    
    return 0;
    
}
