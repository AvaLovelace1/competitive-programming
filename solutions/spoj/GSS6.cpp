/*
 Solution to GSS6 - Can you answer these queries VI by Ava Pun
 Key concepts: split-merge treap
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
const int MAX = 1e5 + 5;

int T, N, Q;
int arr[MAX];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int val, pri, sz, tot;
    int sum[4];
    node *l, *r;
    node(int v) {
        val = v;
        pri = rng();
        sz = 1;
        tot = val;
        sum[0] = sum[1] = val;
        sum[2] = sum[3] = max(0, val);
        l = r = 0;
    }
};

node *root;

inline int sz(node *u) {
    return u ? u->sz : 0;
}

inline int tot(node *u) {
    return u ? u->tot : 0;
}

inline int sum(node *u, int id) {
    if (u) {
        return u->sum[id];
    } else if (id == 1) {
        return -INF;
    } else {
        return 0;
    }
}

inline void upd(node *u) {
    if (u) {
        u->sz = sz(u->l) + sz(u->r) + 1;
        u->sum[0] = sum(u->l, 0) + sum(u->r, 0) + u->val;
        u->sum[1] = max(max(sum(u->l, 1), sum(u->r, 1)), sum(u->l, 3) + sum(u->r, 2) + u->val);
        u->sum[2] = max(sum(u->l, 2), sum(u->l, 0) + u->val + sum(u->r, 2));
        u->sum[3] = max(sum(u->r, 3), sum(u->r, 0) + u->val + sum(u->l, 3));
    }
}

void split(node *p, node *&l, node *&r, int pos) {
    if (!p) {
        l = r = 0;
    } else if (sz(p->l) + 1 < pos) {
        split(p->r, p->r, r, pos - sz(p->l) - 1);
        l = p;
    } else {
        split(p->l, l, p->l, pos);
        r = p;
    }
    upd(p);
}

void merge(node *&p, node *l, node *r) {
    if (!l || !r) {
        p = l ? l : r;
    } else if (l->pri > r->pri) {
        merge(l->r, l->r, r);
        p = l;
    } else {
        merge(r->l, l, r->l);
        p = r;
    }
    upd(p);
}

void heapify(node *u) {
    if (!u) {
        return;
    }
    node *maxU = u;
    if (u->l && u->l->pri > maxU->pri) {
        maxU = u->l;
    }
    if (u->r && u->r->pri > maxU->pri) {
        maxU = u->r;
    }
    if (maxU != u) {
        swap(maxU->pri, u->pri);
        heapify(maxU);
    }
    upd(u);
}

node* build(int l, int r) {
    if (r < l) {
        return 0;
    }
    int m = (l + r) / 2;
    node *u = new node(arr[m]);
    u->l = build(l, m - 1);
    u->r = build(m + 1, r);
    heapify(u);
    upd(u);
    return u;
}

void ins(node *&u, node *x, int pos) {
    if (!u) {
        u = x;
    } else if (u->pri < x->pri) {
        split(u, x->l, x->r, pos);
        u = x;
    } else if (sz(u->l) + 1 < pos) {
        ins(u->r, x, pos - sz(u->l) - 1);
    } else {
        ins(u->l, x, pos);
    }
    upd(u);
}

inline void ins(int pos, int x) {
    ins(root, new node(x), pos);
}

void del(node *&u, int pos) {
    if (!u) {
        return;
    } else if (sz(u->l) + 1 < pos) {
        del(u->r, pos - sz(u->l) - 1);
    } else if (sz(u->l) + 1 > pos) {
        del(u->l, pos);
    } else {
        node *tmp = u;
        merge(u, u->l, u->r);
        free(tmp);
    }
    upd(u);
}

inline void del(int pos) {
    del(root, pos);
}

void repl(node *u, int pos, int x) {
    if (!u) {
        return;
    } else if (sz(u->l) + 1 < pos) {
        repl(u->r, pos - sz(u->l) - 1, x);
    } else if (sz(u->l) + 1 > pos) {
        repl(u->l, pos, x);
    } else {
        u->val = x;
    }
    upd(u);
}

inline void repl(int pos, int x) {
    repl(root, pos, x);
}

inline int quer(int l, int r) {
    node *a, *b, *c;
    split(root, a, b, l);
    split(b, b, c, r - l + 2);
    int ret = sum(b, 1);
    merge(b, b, c);
    merge(root, a, b);
    return ret;
}

inline void traverse(node *u) {
    if (u) {
        traverse(u->l);
        printf("%d ", u->val);
        traverse(u->r);
    }
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    root = build(1, N);

    scanf("%d", &Q);
    int x, y;
    char c;
    for (int i = 1; i <= Q; i++) {
        scanf(" %c", &c);
        if (c == 'D') {
            scanf("%d", &x);
            del(x);
        } else {
            scanf("%d%d", &x, &y);
            if (c == 'I') {
                ins(x, y);
            } else if (c == 'R') {
                repl(x, y);
            } else {
                printf("%d\n", quer(x, y));
            }   
        }
    }

    return 0;
}
