/*
 * Solution to Installing Apps by Ava Pun
 * Key concepts: knapsack dynamic programming, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 505;

int N, C;
struct app {
    int d, e, id;
} arr[MAX];

int mxTime(app a, app b) {
    int t1 = a.d;
    int t2 = a.e + b.d;
    return max(t1, t2);
}

bool comp(app a, app b) {
    return a.e + b.d < b.e + a.d;
}

int dp[505][10005];
bool took[505][10005];

int solve(int n, int c) {
    int &ans = dp[n][c];
    if (ans != -1) return ans;
    else if (c > C) return -INF;
    else if (n > N) return 0;
    else {
        int take = -INF;
        if (c + arr[n].d <= C) {
            take = 1 + solve(n + 1, c + arr[n].e);
        }
        int dont = solve(n + 1, c);

        took[n][c] = (take > dont);
        return ans = max(take, dont);
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 1; i <= N; ++i) {
        int d, e;
        cin >> d >> e;
        d = max(d, e);
        arr[i] = app{d, e, i};
    }
    sort(arr + 1, arr + N + 1, comp);

    FILL(dp, -1);
    
    int ans = solve(1, 0);
    cout << ans << '\n';
    if (ans > 0) {
        int c = 0;
        bool first = true;
        for (int i = 1; i <= N; ++i) {
            if (took[i][c]) {
                if (first) {
                    first = false;
                } else {
                    cout << ' ';
                }
                cout << arr[i].id;
                c += arr[i].e;
            }
        }
        cout << '\n';
    }

}
