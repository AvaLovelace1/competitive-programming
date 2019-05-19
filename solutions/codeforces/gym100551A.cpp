/*
 Solution to Connect and Disconnect by Ava Pun
 Key concepts: disjoint set, segment tree, divide and conquer offline queries
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 5;
const double EPS = 1e-9;

int N, K;
vii tree[2 * MAX];
map<pii, int> pre;
bool quers[MAX];
int ans[MAX];
int par[MAX], rnk[MAX];
stack<pair<pii, bool>> st;
int NC;

int Find(int x) {
    return par[x] != x ? Find(par[x]) : x;
}

inline bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        st.push({{a, b}, 0});
        return 0;
    }
    if (rnk[a] < rnk[b]) {
        swap(a, b);
    }
    pair<pii, bool> e = {{a, b}, 0};
    par[b] = a;
    if (rnk[a] == rnk[b]) {
        rnk[a]++;
        e.s = 1;
    }
    NC--;
    st.push(e);
    return 1;
}

inline void undo() {
    if (st.empty()) {
        return;
    }
    int a = st.top().f.f, b = st.top().f.s;
    bool r = st.top().s;
    st.pop();
    if (a == b) {
        return;
    }
    NC++;
    if (r) {
        rnk[a]--;
    }
    par[b] = b;
}

inline void upd(int l, int r, pii p) {
    l += K - 1, r += K - 1;
    while (l <= r) {
        if (l & 1) {
            tree[l].pb(p);
            l++;
        }
        if (!(r & 1)) {
            tree[r].pb(p);
            r--;
        }
        l >>= 1, r >>= 1;
    }
}

void dfs(int u) {
    for (auto p : tree[u]) {
        Union(p.f, p.s);
    }
    if (u >= K) {
        if (quers[u - K + 1]) {
            ans[u - K + 1] = NC;
        }
    } else {
        dfs(u << 1);
        dfs(u << 1 | 1);
    }
    for (int i = 1; i <= tree[u].size(); i++) {
        undo();
    }
}

int main() {

    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);

    scanf("%d%d", &N, &K);
    char c;
    int u, v;
    for (int i = 1; i <= K; i++) {
        scanf(" %c", &c);
        if (c == '?') {
            quers[i] = 1;
        } else {
            scanf("%d%d", &u, &v);
            if (u > v) {
                swap(u, v);
            }
            pii p = {u, v};
            if (c == '+') {
                pre[p] = i;
            } else {
                upd(pre[p], i - 1, p);
                pre.erase(p);
            }
        }
    }
    for (auto p : pre) {
        upd(p.s, K, p.f);
    }
    
    NC = N;
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    dfs(1);
    for (int i = 1; i <= K; i++) {
        if (quers[i]) {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
