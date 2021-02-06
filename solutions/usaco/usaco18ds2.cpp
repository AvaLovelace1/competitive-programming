/*
 * Solution to USACO '18 December S2 - Convention II by Ava Pun
 * Key concepts: simulation, priority queue
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N;
struct cow {
    int rnk, t, a;
} arr[MAX];

bool compT(cow a, cow b) {
    return a.t < b.t;
}
struct compRnk {
    bool operator() (cow a, cow b) {
        return a.rnk > b.rnk;
    }
};

int main() {

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int t, a;
        cin >> t >> a;
        arr[i] = cow{i, t, a};
    }
    sort(arr + 1, arr + N + 1, compT);

    int ans = 0;
    int cnt = 0, ptr = 1;
    int t = 0;
    priority_queue<cow, vector<cow>, compRnk> pq;
    while (cnt < N) {
        if (pq.empty()) {
            t = max(t, arr[ptr].t);
        }
        while (ptr <= N && arr[ptr].t <= t) {
            pq.push(arr[ptr]);
            ++ptr;
        }
        cow nxt = pq.top();
        pq.pop();
        ans = max(ans, t - nxt.t);
        ++cnt;
        t += nxt.a;
    }
    cout << ans << '\n';

}
