/*
 * Solution to COCI '20 Contest 3 #1 Knjige by Ava Pun
 * Key concepts: implementation, sorting
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
const int MAX = 105;

int N;
vi shelf[2];
int hand[2];
struct Action {
    bool t, h, s;
};
vector<Action> ans;

void move(Action a) {
    if (a.t) hand[a.h] = shelf[a.s].back(), shelf[a.s].pop_back();
    else shelf[a.s].pb(hand[a.h]);
    ans.pb(a);
}

void transfer() {
    int j = SZ(shelf[0]) - (int) (min_element(shelf[0].begin(), shelf[0].end()) - shelf[0].begin());
    REP(i, 1, j-1) move({1, 1, 0}), move({0, 1, 1});
    move({1, 0, 0});
    REP(i, 1, j-1) move({1, 1, 1}), move({0, 1, 0});
    move({0, 0, 1});
}

void solve() {
    REP(i, 1, N) transfer();
    REP(i, 1, N) move({1, 1, 1}), move({0, 1, 0});
    cout << ans.size() << '\n';
    for (auto a : ans)
        cout << (a.t ? "UZMI" : "STAVI") << ' ' << (a.h ? 'D' : 'L') << ' ' << (a.s ? 'D' : 'L') << '\n';
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    shelf[0].resize(N);
    REV(i, N-1, 0) {
        cin >> shelf[0][i];
    }

    solve();

}
