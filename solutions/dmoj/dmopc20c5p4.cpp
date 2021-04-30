/*
 * Solution to DMOPC '20 Contest 5 P4 - Slacking Off by Ava Pun
 * Key concepts: hashing, brute force
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
const int MOD[] = {1000000007, 1000000009};
const double EPS = 1e-9;
const int MAX = 5e5 + 5;
const int RTMAX = 710;
const int BASE[] = {3, 2};

int N, M;
string arrStr[MAX];
bitset<MAX> arr[RTMAX];
ll power[2][MAX];
vector<ll> hshCol[2][MAX];

void initPow(int maxPow, ll power[], int BASE, int MOD) {
    power[0] = 1;
    for (int i = 1; i <= maxPow; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
}

void initHshCol(int c, vector<ll> &hsh, int BASE, int MOD) {
    hsh.resize(N + 1);
    hsh[0] = 0;
    for (int i = 1; i <= N; i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + arr[i - 1][c]) % MOD;
    }
}

ll getHsh(int l, int r, vector<ll> &hsh, ll power[], int MOD) {
    ++l, ++r;
    return (hsh[r] - hsh[l - 1] * power[r - (l - 1)] % MOD + MOD) % MOD;
}

ll computeHsh(int r1, int r2, int c) {
    return (getHsh(r1, r2, hshCol[0][c], power[0], MOD[0]) << 32)
        + getHsh(r1, r2, hshCol[1][c], power[1], MOD[1]);
}

ll countRectsInChunk(vector<ll> &hashes) {
    sort(ALL(hashes));
    ll ret = 0, run = 0;
    REP(i, 0, SZ(hashes)) {
        if (i == SZ(hashes) || (i > 0 && hashes[i] != hashes[i - 1])) {
            ret += run * (run - 1) / 2;
            run = 0;
        }
        ++run;
    }
    return ret;
}

ll countUglyRects(int r1, int r2) {
    ll ret = 0;
    vector<ll> hashes;
    REP(c, 0, M) {
        if (c == M || arr[r1][c] != arr[r2][c]) {
            ret += countRectsInChunk(hashes);
            hashes.clear();
        } else if (c != M) {
            hashes.pb(computeHsh(r1, r2, c));
        }
    }
    return ret;
}

ll solve() {
    ll ret = 0;
    REP(r1, 0, N - 1) {
        REP(r2, r1 + 1, N - 1) {
            ret += countUglyRects(r1, r2);
        }
    }
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 0, N - 1) {
        cin >> arrStr[i];
    }
    if (N > M) {
        swap(N, M);
        REP(i, 0, N - 1) {
            REP(j, 0, M - 1) {
                arr[i][j] = (arrStr[j][i] == 'Y');
            }
        }
    } else {
        REP(i, 0, N - 1) {
            REP(j, 0, M - 1) {
                arr[i][j] = (arrStr[i][j] == 'Y');
            }
        }
    }

    REP(id, 0, 1) {
        initPow(N, power[id], BASE[id], MOD[id]);
        REP(i, 0, M - 1) {
            initHshCol(i, hshCol[id][i], BASE[id], MOD[id]);
        }
    }

    cout << solve() << '\n';    

}
