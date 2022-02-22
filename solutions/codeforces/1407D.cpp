/*
 * Solution to Discrete Centrifugal Jumps by Ava Pun
 * Key concepts: dynamic programming, all nearest smaller values
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
const int MAX = 3e5 + 5;

int N;
int arr[MAX], dp[MAX];
vi adj[MAX];

void findNearest() {
    stack<int> st;

    while (!st.empty()) st.pop();
    REP(i, 1, N) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if (!st.empty()) adj[i].pb(st.top());
        st.push(i);
    }

    while (!st.empty()) st.pop();
    REV(i, N, 1) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if (!st.empty()) adj[st.top()].pb(i);
        st.push(i);
    }

    while (!st.empty()) st.pop();
    REP(i, 1, N) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if (!st.empty()) adj[i].pb(st.top());
        st.push(i);
    }

    while (!st.empty()) st.pop();
    REV(i, N, 1) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if (!st.empty()) adj[st.top()].pb(i);
        st.push(i);
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        cin >> arr[i];
    }

    findNearest();

    FILL(dp, INF);
    dp[1] = 0;
    REP(i, 2, N) {
        TRAV(j, adj[i]) dp[i] = min(dp[i], dp[j]+1);
    }
    cout << dp[N] << '\n';

}
