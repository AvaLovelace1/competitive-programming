/*
 * Solution to Grid Paths by Ava Pun
 * Key concepts: brute force, backtracking, pruning
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

string S;
bool filled[7][7];
map<char, pii> dirs = {{'D', {1, 0}}, {'U', {-1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};

inline bool valid(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7 && !filled[r][c];
}

inline bool blocked(pii dir1, pii dir2, pii dir3, pii dir4, int r, int c) {
    int r1 = r + dir1.f, c1 = c + dir1.s;
    int r2 = r + dir2.f, c2 = c + dir2.s;
    int r3 = r + dir3.f, c3 = c + dir3.s;
    int r4 = r + dir4.f, c4 = c + dir4.s;
    return !valid(r1, c1) && !valid(r2, c2) && valid(r3, c3) && valid(r4, c4);
}

bool nook(int r, int c) {
    if (!valid(r, c)) {
        return false;
    }
    if (r == 6 && c == 0) {
        return false;
    }
    int cnt = 0;
    for (auto &p : dirs) {
        auto dir = p.s;
        int r1 = r + dir.f, c1 = c + dir.s;
        cnt += !valid(r1, c1);
    }
    return cnt >= 3;
}

int solve(int n, int r, int c) {

    if (n == 48) {
        return r == 6 && c == 0;
    }
    if (r == 6 && c == 0) {
        return 0;
    }
    if (blocked(dirs['U'], dirs['D'], dirs['L'], dirs['R'], r, c) ||
        blocked(dirs['L'], dirs['R'], dirs['U'], dirs['D'], r, c)) {
        return 0;
    }

    filled[r][c] = 1;
    
    int ret = 0;
    vii nxt;
    for (auto &p : dirs) {
        auto ch = p.f;
        auto dir = p.s;
        int r1 = r + dir.f, c1 = c + dir.s;
        if ((S[n] == '?' || S[n] == ch) && valid(r1, c1)) {
            if (nook(r1, c1)) {
                nxt.clear();
                nxt.pb({r1, c1});
                break;
            } else {
                nxt.pb({r1, c1});
            }
        }
    }
    for (auto p : nxt) {
        ret += solve(n + 1, p.f, p.s);
    }

    filled[r][c] = 0;

    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S;

    cout << solve(0, 0, 0) << '\n';
}
