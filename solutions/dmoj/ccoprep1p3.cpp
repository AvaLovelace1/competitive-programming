/*
 Solution to CCO Preparation Test 1 - K-th Rank Student by Ava Pun
 Key concepts: graph theory, disjoint set, binary search tree, treap
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, Q;
int par[MAX], ranks[MAX];
struct node{
    int key, val, size, p;
    node *child[2];
    node(int k, int v) {
        key = k;
        val = v;
        size = 1;
        p = rand();
        child[0] = child[1] = 0;
    }
} *root[MAX];

inline int getSize(node *u) {
    return u ? u->size : 0;
}

inline void updSize(node *u) {
    if (u) {
        u->size = getSize(u->child[0]) + getSize(u->child[1]) + 1;
    }
}

void rotate(node *&u, bool dir) {
    node *c = u->child[dir];
    u->child[dir] = c->child[!dir];
    c->child[!dir] = u;
    updSize(u), updSize(c);
    u = c;
}

void insert(node *&u, node *i) {
    if (!u) {
        u = i;
        return;
    }
    bool dir = u->key < i->key;
    insert(u->child[dir], i);
    if (u->child[dir]->p > u->p) {
        rotate(u, dir);
    }
    updSize(u);
}

int valAt(node *u, int idx) {
    if (!u) {
        return -1;
    }
    if (getSize(u->child[0]) >= idx) {
        return valAt(u->child[0], idx);
    } else {
        if (getSize(u->child[0]) + 1 == idx) {
            return u->val;
        } else {
            return valAt(u->child[1], idx - getSize(u->child[0]) - 1);
        }
    }
}

void merge(int n, node *v) {
    if (!v) {
        return;
    }
    merge(n, v->child[0]), merge(n, v->child[1]);
    insert(root[n], v);
}

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) {
        return;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
        merge(b, root[a]);
    } else {
        par[b] = a;
        merge(a, root[b]);
        if (ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        par[i] = i;
        insert(root[i], new node(n, i));
    }

    char c;
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    
    scanf("%d", &Q);
    while (Q--) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'Q') {
            printf("%d\n", valAt(root[Find(a)], b));
        } else {
            Union(a, b);
        }
    }
    
    return 0;
    
}
