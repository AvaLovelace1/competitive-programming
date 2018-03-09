/*
 Solution to CCO Preparation Test 1 - Double Cross by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 9;
const int MAX = 10005;

int R, C, N;
vector< vector<int> > u, d, l, r;
vector< vector<bool> > grid;
ll cntBit[MAX], addBit[MAX], subBit[MAX];
stack<pii> st;

void update(int pos, ll x, ll bit[]) {
    for (int i = pos; i < MAX; i += i & -i) {
        bit[i] = (bit[i] + x) % MOD;
        bit[i] = (bit[i] + MOD) % MOD;
    }
}

ll query(int pos, ll bit[]) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
        ans %= MOD;
    }
    return ans;
}

void update(int prev, int prevM, ll sign) {
    if (prev != 0 && prevM != 0) {
        update(prev, sign * prevM, cntBit);
        update(prev, sign * prev * prevM, addBit);
        update(prev, sign * prev * (prev + 1) / 2 * prevM % MOD, subBit);
    }
}

void clearSt() {
    while (!st.empty()) {
        pii x = st.top();
        st.pop();
        update(x.first, x.second, -1);
    }
}

int main() {
    
    scanf("%d%d%d", &R, &C, &N);
    u.resize(R + 2);
    d.resize(R + 2);
    l.resize(R + 2);
    r.resize(R + 2);
    grid.resize(R + 2);
    for (int i = 0; i < R + 2; i++) {
        u[i].resize(C + 2);
        d[i].resize(C + 2);
        l[i].resize(C + 2);
        r[i].resize(C + 2);
        grid[i].resize(C + 2);
    }
    for (int i = 0; i < R + 2; i++) {
        for (int j = 0; j < C + 2; j++) {
            grid[i][j] = 1;
        }
    }
    
    int a, b;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &a, &b);
        grid[a][b] = 0;
    }
    
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) {
            u[i][j] = grid[i][j] ? 1 + u[i - 1][j] : 0;
        }
        for (int i = R; i >= 1; i--) {
            d[i][j] = grid[i][j] ? 1 + d[i + 1][j] : 0;
        }
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            l[i][j] = grid[i][j] ? 1 + l[i][j - 1] : 0;
        }
        for (int j = C; j >= 1; j--) {
            r[i][j] = grid[i][j] ? 1 + r[i][j + 1] : 0;
        }
    }
    
    ll ans = 0;
    for (int j = 1; j <= C; j++) {
        int curr = 0, prev = 0, prevM = 0;
        for (int i = 1; i <= R; i++) {
            if (!grid[i][j]) {
                curr = 0, prev = 0, prevM = 0;
                clearSt();
            } else {
                curr = min(l[i][j], r[i][j]) - 1;
                if (curr > 1) {
                    ll currAns = 0;
                    currAns += (query(MAX - 1, cntBit) - query(curr - 2, cntBit) + MOD) % MOD * (curr * (curr - 1) / 2) % MOD;
                    currAns %= MOD;
                    currAns += (query(curr - 2, addBit) * curr % MOD - query(curr - 2, subBit) + MOD) % MOD;
                    currAns %= MOD;
                    ans = (ans + currAns * d[i + 1][j] % MOD) % MOD;
                }
            }
            if (prev != 0 && prevM != 0) {
                update(prev, prevM, 1);
                st.push({prev, prevM});
            }
            prev = curr;
            prevM = u[i - 1][j];
        }
        clearSt();
    }
    printf("%lld", ans);
    
    return 0;
    
}
