/*
 Solution to Palindromic characteristics by Ava Pun
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5002;
const double EPS = 1e-7;

int N;
string S;
int dp[MAX][MAX];
bool palin[MAX][MAX];
int ans[MAX];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    S = " " + S;
    N = S.length() - 1;

    for (int i = 1; i <= N; i++) {
        palin[i][i - 1] = palin[i][i] = 1;
        dp[i][i] = 1;
    }

    for (int l = 2; l <= N; l++) {
        for (int i = 1; i <= N; i++) {
            int j = i + l - 1;
            palin[i][j] = palin[i + 1][j - 1] && S[i] == S[j];
            if (palin[i][j]) {
                dp[i][j] = dp[i][i + l / 2 - 1] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            ans[dp[i][j]]++;
        }
    }
    for (int i = N; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= N; i++) {
        printf("%d", ans[i]);
        printf(i == N ? "\n" : " ");
    }
    
    return 0;
}
