/*
 * Solution to Strange Game On Matrix by Ava Pun
 * Key concepts: brute force, greedy algorithms
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

int N, M, K;
bool arr[105][105];

pii solve(int col) {
    int score = 0, cost = 0;
    int curScore = 0, curCost = 0;
    REP(i, 1, N) {
        if (arr[col][i]) {
            curScore = accumulate(arr[col] + i, arr[col] + min(i + K, N + 1), 0);
            if (curScore > score) {
                score = curScore;
                cost = curCost;
            }
            ++curCost;
        }
    }
    return {score, cost};
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M >> K;
    REP(i, 1, N)
        REP(j, 1, M)
            cin >> arr[j][i];

    int score = 0, cost = 0;
    REP(j, 1, M) {
        auto p = solve(j);
        score += p.f;
        cost += p.s;
    }
    cout << score << ' ' << cost << '\n';
}

