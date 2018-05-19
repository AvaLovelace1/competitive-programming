/*
 Solution to COCI '15 Contest 2 #4 Savez by Ava Pun
 Key concepts: hashing, dynamic programming
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
const int BASE = 31;
const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

int N;
string S;
ll power[MAX];
unordered_map<ll, int> dp;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    power[0] = 1;
    for (int i = 1; i < MAX; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
    
    cin >> N;
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        
        cin >> S;
        ll hsh1 = 0, hsh2 = 0;
        int idx1 = 0, idx2 = (int) S.length() - 1;
        
        int maxN = 1;
        while (idx2 >= 0) {
            hsh1 = (hsh1 + (S[idx1] - 'A' + 1) * power[idx1] % MOD) % MOD;
            hsh2 = (hsh2 * BASE % MOD + (S[idx2] - 'A' + 1)) % MOD;
            if (hsh1 == hsh2) {
                maxN = max(maxN, dp[hsh1] + 1);
            }
            idx1++, idx2--;
        }
        dp[hsh1] = maxN;
        ans = max(ans, maxN);
        
    }
    
    cout << ans << '\n';
    
    return 0;
}
