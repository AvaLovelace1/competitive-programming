/*
 Solution to DMOPC '14 Contest 3 P5 - Not Enough Servers! by Ava Pun
 Key concepts: bitmask dynamic programming
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int N, M;
string arr[25];
int dp[55][(1 << 20) + 5];

int nxt(int n, int b) {
    for (int i = 0; i < N; i++) {
        if (arr[i][n - 1] == 'X') {
            b &= ~(1 << i);
        }
    }
    return b;
}

int solve(int n, int b) {
    if (dp[n][b] == -1) {
        if (n == 0) {
            if (b == 0) {
                dp[n][b] = 0;
            } else {
                dp[n][b] = INF;
            }
        } else {
            int b0 = nxt(n, b);
            dp[n][b] = min(solve(n - 1, b), solve(n - 1, b0) + 1);
        }
    }
    return dp[n][b];
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    string str;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (char c : str) {
            if (c == 'X') {
                arr[cnt++] = str;
                break;
            }
        }
    }
    N = cnt;
    
    memset(dp, -1, sizeof(dp));
    int ans = solve(M, (1 << N) - 1);
    if (ans == 0) {
        cout << "1\n1\n";
        return 0;
    }
    cout << ans << "\n";
    int b = (1 << N) - 1;
    for (int n = M; n > 0; n--) {
        int b0 = nxt(n, b);
        if (dp[n][b] == dp[n - 1][b0] + 1) {
            printf("%d ", n);
            b = b0;
        }
    }
    printf("\n");
    
    return 0;
    
}
