/*
 Solution to IOI '05 P4 - Birthday by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef complex<double> cd;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
int arr[MAX], inv[MAX];
deque<int> q[2];

inline int solve() {
    q[0].clear(), q[1].clear();
    for (int i = 1; i <= N; i++) {
        int k1 = abs(inv[i] - i), k2 = N - abs(inv[i] - i);
        if (!(k1 <= k2 ^ inv[i] > i)) {
            q[0].pb(min(k1, k2));
        } else {
            q[1].pb(min(k1, k2));
        }
    }
    sort(q[0].begin(), q[0].end());
    sort(q[1].begin(), q[1].end(), greater<int>());
    int ans = N;
    for (int i = 0; i < N; i++) {
        int cur = 0;
        if (!q[0].empty()) {
            cur = max(cur, q[0].back() - i);
        }
        if (!q[1].empty()) {
            cur = max(cur, q[1].front() + i);
        }
        ans = min(ans, cur);
        queue<int> tmp[2];
        while (!q[0].empty() && q[0].front() - i == 0) {
            q[0].pop_front();
            tmp[1].push(1 - (i + 1));
        }
        while (!q[1].empty() && q[1].front() + i == N / 2) {
            q[1].pop_front();
            tmp[0].push(N / 2 - !(N % 2) + (i + 1));
        }
        for (int j = 0; j < 2; j++) { 
            while (!tmp[j].empty()) {
                q[j].pb(tmp[j].front());
                tmp[j].pop();
            }
        }
    }
    return ans;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        inv[arr[i]] = i;
    }
    int ans = solve();
    reverse(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        inv[arr[i]] = i;
    }
    ans = min(ans, solve());
    printf("%d\n", ans);

    return 0;
}
