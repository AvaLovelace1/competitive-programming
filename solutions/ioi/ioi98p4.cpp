/*
 Solution to IOI '98 P4 - Picture by Ava Pun
 Key concepts: line sweep
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

int N, N1, M1;
pii A[MAX], B[MAX];
vi cpr[2];
int val[2 * MAX], diff[2 * MAX], active[2][2 * MAX];
vii events[2][2 * MAX];

inline int getIdx(int x, int t) {
    return (int) (lower_bound(cpr[t].begin(), cpr[t].end(), x) - cpr[t].begin());
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d%d", &A[i].f, &A[i].s, &B[i].f, &B[i].s);
        cpr[0].pb({A[i].f}), cpr[0].pb({B[i].f});
        cpr[1].pb({A[i].s}), cpr[1].pb({B[i].s});
    }

    for (int i = 0; i < 2; i++) {
        cpr[i].pb(-INF);
        sort(cpr[i].begin(), cpr[i].end());
        cpr[i].erase(unique(cpr[i].begin(), cpr[i].end()), cpr[i].end());
    }
    N1 = (int) cpr[0].size() - 1;
    M1 = (int) cpr[1].size() - 1;
    for (int i = 1; i < M1; i++) {
        val[i] = cpr[1][i + 1] - cpr[1][i];
    }

    for (int i = 1; i <= N; i++) {
        events[1][getIdx(A[i].f, 0)].pb({getIdx(A[i].s, 1), getIdx(B[i].s, 1)});
        events[0][getIdx(B[i].f, 0)].pb({getIdx(A[i].s, 1), getIdx(B[i].s, 1)});
    }

    int ans = 0, pre = 0;
    for (int i = 1; i <= N1; i++) {

        int row = cpr[0][i];

        int pref = diff[0], pref0 = 0;
        for (int j = 1; j <= M1; j++) {
            pref0 = pref;
            pref += diff[j];
            if ((pref > 0 && pref0 == 0) || (pref0 > 0 && pref == 0)) {
                ans += row - pre;
            }
        }

        for (auto p : events[0][i]) {
            diff[p.f]--, diff[p.s]++;
        }
        for (int j = 0; j < 2; j++) {
            for (auto p : events[j][i]) {
                active[j][p.f]++, active[j][p.s]--;
            }
        }

        pref = diff[0];
        int prefA0 = active[0][0], prefA1 = active[1][0];
        for (int j = 1; j <= M1; j++) {
            pref += diff[j];
            prefA0 += active[0][j];
            prefA1 += active[1][j];
            if ((prefA0 > 0 ^ prefA1 > 0) && pref == 0) {
                ans += val[j];
            }
        }

        for (auto p : events[1][i]) {
            diff[p.f]++, diff[p.s]--;
        }
        for (int j = 0; j < 2; j++) {
            for (auto p : events[j][i]) {
                active[j][p.f]--, active[j][p.s]++;
            }
        }

        pre = row;
    }
    printf("%d\n", ans);

    return 0;
}
