/*
 * Solution to COCI '20 Contest 3 #3 Sateliti by Ava Pun
 * Key concepts: hashing, binary search
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
const int MAX = 1005;

const int BASE = 3;

int N, M;
char arr[2*MAX][2*MAX];
ll hshLine[2*MAX][2*MAX], hshRect[2*MAX][MAX];
ll power[4*MAX*MAX];

ll getHsh(int l, int r, ll hsh[]) {
    return (hsh[r] - hsh[l-1] * power[r-l+1] % MOD + MOD) % MOD;
}

ll getHshRect(int col, int a, int b) {
    return (hshRect[b][col] - hshRect[a-1][col] * power[M*(b-a+1)] % MOD + MOD) % MOD;
}

void calcHsh() {
    power[0] = 1;
    REP(i, 1, 4*N*M) power[i] = power[i-1] * BASE % MOD;

    REP(i, 1, 2*N) {
        REP(j, 1, 2*M) {
            hshLine[i][j] = (hshLine[i][j-1] * BASE + (arr[i][j] == '*') + 1) % MOD;
        }
    }

    REP(i, 1, 2*N) {
        REP(j, 1, M) {
            hshRect[i][j] = (hshRect[i-1][j] * power[M] + getHsh(j, j+M-1, hshLine[i])) % MOD;
        }
    }
}

pii toIdx(int i1, int j1, int k) {
    --k;
    return {i1 + k / M, j1 + k % M};
}

ll getHsh(int i1, int j1, int k) {
    pii idx = toIdx(i1, j1, k);
    int i2 = idx.f, j2 = idx.s;
    return (getHshRect(j1, i1, i2-1) * power[M] + getHsh(j1, j2, hshLine[i2])) % MOD;
}

bool lt(int i1, int j1, int i2, int j2) {
    int lo = 1, hi = N*M + 1;
    while (lo < hi) {
        int mid = (lo+hi) / 2;
        if (getHsh(i1, j1, mid) == getHsh(i2, j2, mid)) lo = mid+1;
        else hi = mid;
    }
    if (lo == N*M + 1) return 0;
    pii idx1 = toIdx(i1, j1, lo), idx2 = toIdx(i2, j2, lo);
    return arr[idx1.f][idx1.s] < arr[idx2.f][idx2.s];
}

void solve() {
    int i0 = 0, j0 = 0;
    REP(i, 1, N) {
        REP(j, 1, M) {
            if (i0 == 0 || lt(i, j, i0, j0)) i0=i, j0=j;
        }
    }

    REP(i, 1, N) {
        REP(j, 1, M) {
            cout << arr[i0+i-1][j0+j-1];
        }
        cout << '\n';
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 1, N) {
        REP(j, 1, M) {
            char c;
            cin >> c;
            arr[i][j] = arr[i+N][j] = arr[i][j+M] = arr[i+N][j+M] = c;
        }
    }

    calcHsh();
    solve();

}
