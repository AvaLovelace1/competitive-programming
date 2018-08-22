/*
 Solution to IOI '15 P2 - Scales by Ava Pun
 Key concepts: ad hoc, brute force
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1500 + 5;

int order[6], perms[730][6];
int op[MAX], args[MAX][4];
vi adj[MAX];
vii a;

inline int query(int i, int j, int k, int l, int v, int t) {
    a = {{perms[v][i], i}, {perms[v][j], j}, {perms[v][k], k}};
    sort(a.begin(), a.end());
    if (t != 3) {
        return a[t].s;
    } else {
        pii ans = {INF, -1};
        for (pii p : a) {
            if (p.f > perms[v][l]) {
                ans = min(ans, p);
            }
        }
        if (ans.s == -1) {
            return a[0].s;
        } else {
            return ans.s;
        }
    }
}

bool solve(int u, int lvl, vi &curr);

bool check(int u, int lvl, int i, int j, int k, int l, int t, vi &curr) {
    vi tmp[3];
    for (int v : curr) {
        int x = query(i, j, k, l, v, t);
        tmp[x == i ? 0 : x == j ? 1 : 2].pb(v);
    }
    bool good = 1;
    for (int cnt = 0; cnt < 3 && good; cnt++) {
        good &= tmp[cnt].size() <= pow(3, lvl - 1);
    }
    for (int cnt = 0; cnt < 3 && good; cnt++) {
        good &= solve(3 * u + cnt - 1, lvl - 1, tmp[cnt]);
    }
    if (good) {
        op[u] = t;
        adj[u] = {3 * u - 1, 3 * u, 3 * u + 1};
        args[u][0] = i + 1, args[u][1] = j + 1, args[u][2] = k + 1, args[u][3] = l + 1;
    } else {
        good = 0;
    }
    for (int i = 0; i < 3; i++) {
        tmp[i].clear();
    }
    return good;
}

bool solve(int u, int lvl, vi &curr) {
    if (curr.empty()) {
        return 1;
    }
    if (curr.size() == 1) {
        op[u] = curr[0];
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                for (int t = 0; t < 3; t++) {
                    if (check(u, lvl, i, j, k, 0, t, curr)) {
                        return 1;
                    }
                }
                for (int l = k + 1; l < 6; l++) {
                    if (check(u, lvl, i, j, k, l, 3, curr)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void init(int T) {
    for (int i = 0; i < 6; i++) {
        order[i] = i;
    }
    int itr = 0;
    do {
        for (int i = 0; i < 6; i++) {
            perms[itr][i] = order[i];
        }
        itr++;
    } while (next_permutation(order, order + 6));
    vi curr(720);
    for (int i = 0; i < 720; i++) {
        curr[i] = i;
    }
    solve(1, 6, curr);
}

int dfs(int u) {
    if (adj[u].empty()) {
        return op[u];
    }
    int x;
    if (op[u] == 0) {
        x = getLightest(args[u][0], args[u][1], args[u][2]);
    } else if (op[u] == 1) {
        x = getMedian(args[u][0], args[u][1], args[u][2]);
    } else if (op[u] == 2) {
        x = getHeaviest(args[u][0], args[u][1], args[u][2]);
    } else {
        x = getNextLightest(args[u][0], args[u][1], args[u][2], args[u][3]);
    }
    for (int i = 0; i < 3; i++) {
        if (x == args[u][i]) {
            return dfs(adj[u][i]);
        }
    }
    return -1;
}

void orderCoins() {
    int n = dfs(1);
    int ans[6];
    for (int i = 0; i < 6; i++) {
        ans[perms[n][i]] = i + 1;
    }
    answer(ans);
}
