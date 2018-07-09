/*
 Solution to Mock CCC '18 Contest 1 S5 - A Palindrome Problem by Ava Pun
 Key concepts: dynamic programming
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

string S;
int N;
int dp[21][2][2];

inline int noCarry(int i, int l, int r) {
    int ans = INF;
    ans = min(ans, dp[i + 1][0][0] + abs(r - l));
    if (l != 9) {
        ans = min(ans, dp[i + 1][0][1] + abs(r - (l + 1) % 10));
    }
    ans = min(ans, dp[i + 1][1][0] + (10 - r) + l);
    if (l != 9) {
        ans = min(ans, dp[i + 1][1][1] + (10 - r) + (l + 1));
    }
    return ans;
}

inline int carry(int i, int l, int r) {
    int ans = INF;
    ans = min(ans, dp[i + 1][0][0] + (r + 10) - l);
    ans = min(ans, dp[i + 1][0][1] + (r + 10) - (l + 1));
    ans = min(ans, dp[i + 1][1][0] + (10 - r) + (10 - l));
    ans = min(ans, dp[i + 1][1][1] + (10 - r) + (10 - (l + 1) % 10) % 10);
    return ans;
}

int main() {
    
    cin >> S;
    N = (int) S.length();
    
    FILL(dp, INF);
    if (!(N & 1)) {
        dp[N / 2][0][0] = dp[N / 2][1][1] = 0;
    } else {
        int a = S[N / 2] - '0';
        dp[N / 2][0][0] = 0;
        dp[N / 2][0][1] = 10 - a;
        if (a != 9) {
            dp[N / 2][1][0] = 0;
        }            
        dp[N / 2][1][1] = 10 - (a + 1);
    }
    
    for (int i = N / 2 - 1; i >= 0; i--) {
        int l = S[i] - '0', r = S[N - i - 1] - '0';
        dp[i][0][0] = noCarry(i, l, r);
        dp[i][0][1] = carry(i, l, r);
        if (r == 9) {
            dp[i][1][0] = min(dp[i][1][0], dp[i + 1][1][0] + l);
            if (l != 9) {
                dp[i][1][0] = min(dp[i][1][0], dp[i + 1][1][1] + (l + 1));
            }
            dp[i][1][1] = min(dp[i][1][1], dp[i + 1][1][0] + (10 - l));
            dp[i][1][1] = min(dp[i][1][1], dp[i + 1][1][1] + (10 - (l + 1)));
        } else {
            dp[i][1][0] = noCarry(i, l, r + 1);
            dp[i][1][1] = carry(i, l, r + 1);
        }
    }
    
    printf("%d\n", min(dp[0][0][0], dp[0][0][1]));
    
    return 0;
}
