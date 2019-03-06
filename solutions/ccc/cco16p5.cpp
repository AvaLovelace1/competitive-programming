/*
 Solution to CCO '16 P5 - Zombie Apocalypse by Ava Pun
 Key concepts: line sweep, difference array
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2e3 + 5;

int N, M, K, Q;
pii arr[MAX];
vector<pii> events[2][2 * MAX];
int N1, M1;
int diff[2 * MAX], val[2 * MAX];
vi cpress[2];

inline int getIdx(int x, int i) {
    return (int) (lower_bound(cpress[i].begin(), cpress[i].end(), x) - cpress[i].begin());
}

inline ll solve(int Q) {

    for (int i = 0; i < 2; i++) {
        cpress[i].clear();
        for (int j = 0; j <= 2 * K + 1; j++) {
            events[i][j].clear();
        }
    }
    FILL(diff, 0);
    for (int i = 1; i <= K; i++) {
        pii rows = {max(1, arr[i].f - Q), min(N, arr[i].f + Q)};
        pii cols = {max(1, arr[i].s - Q), min(M, arr[i].s + Q)};
        cpress[0].pb(rows.f), cpress[0].pb(rows.s + 1);
        cpress[1].pb(cols.f), cpress[1].pb(cols.s + 1);
    }
    cpress[0].pb(0), cpress[1].pb(0);
    cpress[0].pb(N + 1), cpress[1].pb(M + 1);
    for (int i = 0; i < 2; i++) {
        sort(cpress[i].begin(), cpress[i].end());
        cpress[i].erase(unique(cpress[i].begin(), cpress[i].end()), cpress[i].end());
    }
    N1 = (int) cpress[0].size() - 2;
    M1 = (int) cpress[1].size() - 2;
    for (int i = 1; i <= M1; i++) {
        val[i] = cpress[1][i + 1] - cpress[1][i];
    }
    
    for (int i = 1; i <= K; i++) {
        pii rows = {max(1, arr[i].f - Q), min(N, arr[i].f + Q)};
        pii cols = {max(1, arr[i].s - Q), min(M, arr[i].s + Q)};
        events[1][getIdx(rows.f, 0)].pb({getIdx(cols.f, 1), getIdx(cols.s + 1, 1)});
        events[0][getIdx(rows.s + 1, 0)].pb({getIdx(cols.f, 1), getIdx(cols.s + 1, 1)});
    }

    int pre = 0;
    ll ans = 0;
    for (int i = 1; i <= N1 + 1; i++) {

        int row = cpress[0][i];

        ll tmp = 0;
        int pref = diff[0];
        for (int j = 1; j <= M1; j++) {
            pref += diff[j];
            if (pref > 0) {
                tmp += val[j];
            }
        }
        ans += tmp * (row - pre);

        for (auto p : events[1][i]) {
            diff[p.f]++, diff[p.s]--;
        }
        for (auto p : events[0][i]) {
            diff[p.f]--, diff[p.s]++;
        }
        
        pre = row;
    }

    return ans;
}

int main() {

    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    scanf("%d", &Q);

    if (Q == 0) {
        printf("%d\n", K);
    } else {
        printf("%lld\n", solve(Q) - solve(Q - 1));
    }

    return 0;
}
