/*
 Solution to DMOPC '16 Contest 3 P6 - Long Lost Love by Ava Pun
 Key concepts: persistent segment tree
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, Q;
int NC = 0, NR = 0;
struct node {
    int l, r, ch[2];
    ll tot[3];
} tree[MAX * 40];
int arr[MAX], root[5 * MAX];

inline void up(int u) {
    tree[u].tot[0] = tree[tree[u].ch[0]].tot[0] + tree[tree[u].ch[1]].tot[0];
    tree[u].tot[1] = max(tree[tree[u].ch[0]].tot[1], tree[tree[u].ch[0]].tot[0] + tree[tree[u].ch[1]].tot[1]);
    tree[u].tot[2] = max(tree[tree[u].ch[1]].tot[2], tree[tree[u].ch[1]].tot[0] + tree[tree[u].ch[0]].tot[2]);
}

int build(int l, int r) {
    int u = ++NC;
    tree[u].l = l, tree[u].r = r;
    if (l == r) {
        tree[u].tot[0] = tree[u].tot[1] = tree[u].tot[2] = arr[l];
    } else {
        int m = (l + r) / 2;
        tree[u].ch[0] = build(l, m);
        tree[u].ch[1] = build(m + 1, r);
        up(u);
    }
    return u;
}

int upd(int u, int pos, int x) {
    int v = ++NC;
    tree[v].l = tree[u].l, tree[v].r = tree[u].r;
    if (tree[v].l == tree[v].r) {
        tree[v].tot[0] = tree[v].tot[1] = tree[v].tot[2] = x;
    } else {
        int m = (tree[v].l + tree[v].r) / 2;
        bool b = pos > m;
        tree[v].ch[!b] = tree[u].ch[!b];
        tree[v].ch[b] = upd(tree[u].ch[b], pos, x);
        up(v);
    }
    return v;
}

ll quer(int u, int l, int r, int idx) {
    if (tree[u].l == l && tree[u].r == r) {
        return tree[u].tot[idx];
    } else {
        int m = (tree[u].l + tree[u].r) / 2;
        if (r <= m) {
            return quer(tree[u].ch[0], l, r, idx);
        } else if (l >= m + 1) {
            return quer(tree[u].ch[1], l, r, idx);
        } else {
            if (idx == 0) {
                return quer(tree[u].ch[0], l, m, 0) + quer(tree[u].ch[1], m + 1, r, 0);
            } else if (idx == 1) {
                return max(quer(tree[u].ch[0], l, m, 1), quer(tree[u].ch[0], l, m, 0) + quer(tree[u].ch[1], m + 1, r, 1));
            } else {
                return max(quer(tree[u].ch[1], m + 1, r, 2), quer(tree[u].ch[1], m + 1, r, 0) + quer(tree[u].ch[0], l, m, 2));
            }
        }
    }
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    root[0] = build(1, N);

    scanf("%d", &Q);
    int a, b;
    char c;
    for (int i = 1; i <= Q; i++) {
        scanf(" %c%d", &c, &a);
        if (c == 'G') {
            NR++;
            root[NR] = root[a];
        } else {
            scanf("%d", &b);
            if (c == 'U') {
                NR++;
                root[NR] = upd(root[NR - 1], a, b);
            } else if (c == 'P') {
                printf("%lld\n", quer(root[NR], a, b, 1));
            } else {
                printf("%lld\n", quer(root[NR], a, b, 2));
            }
        }
    }

    return 0;
}
