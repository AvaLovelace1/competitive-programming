/*
 * Solution to Meadow by Ava Pun
 * Key concepts: dynamic programming, greedy algorithms, all nearest smaller values
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 5;

int N, K, W;
int arr[MAX];
int dp[505][505];
int pre[MAX], nxt[MAX];

int solve() {
    dp[0][0] = 0;

    REP(n, 1, N) {
        REP(k, 0, n) {
            int &ans = dp[n][k];
            if (k > 0) {
                int h = INF;
                REV(i, n, max(1, n - W + 1)) {
                    int w = n - i + 1;
                    h = min(h, arr[i]);
                    ans = max(ans, dp[i - 1][k - 1] + w * h);
                }
            }
            if (k <= n - 1) ans = max(ans, dp[n - 1][k]);
        }
    }

    return dp[N][K];
}

int solveW1() {
    sort(arr + 1, arr + N + 1);
    int ans = 0;
    REV(i, N, N - K + 1) ans += arr[i];
    return ans;
}

void process(int i, stack<int> &st, int pre[]) {
    while (arr[st.top()] >= arr[i]) st.pop();
    pre[i] = st.top();
    st.push(i);
}

int solveK1() {
    arr[0] = arr[N + 1] = -1;

    stack<int> st;
    st.push(0);
    REP(i, 1, N) process(i, st, pre);

    while (!st.empty()) st.pop();
    st.push(N + 1);
    REV(i, N, 1) process(i, st, nxt);

    int ans = 0;
    REP(i, 1, N) {
        int w = min(W, nxt[i] - pre[i] - 1);
        ans = max(ans, arr[i] * w);
    }
    return ans;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> K >> W;
    REP(i, 1, N) {
        cin >> arr[i];
    }

    cout << (W == 1 ? solveW1() : K == 1 ? solveK1() : solve()) << '\n';
}
