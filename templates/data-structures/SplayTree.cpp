/*
 ~ Splay Tree Balanced Binary Search Tree ~
 
 Not technically a balanced binary search tree, but has the same time complexity.
 Every time a node is accessed, it is "splayed" to the top.
 Thus, more commonly accessed nodes can be found faster.
 Remember to splay every time you try to access a node, even if it is unsuccessful.
 
 Time complexity:
 Insert - O(logN)
 Delete - O(logN)
 Search - O(logN)
 Access - O(logN)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int Q;

struct node{
    int key, val, size, cnt;
    node *par, *child[2];
    node(int k) {
        key = k;
        val = k;
        size = 1;
        cnt = 1;
        par = child[0] = child[1] = this;
    }
    node(int k, int v) {
        key = k;
        val = v;
        size = 1;
        cnt = 1;
        par = child[0] = child[1] = this;
    }
};

typedef pair<node*, node*> pnn;

node *null = new node(0, 0);
node *root = null;

inline int getSize(node *u) {
    return u == null ? 0 : u->size;
}

inline void updSize(node *u) {
    if (u != null) {
        u->size = u->cnt + getSize(u->child[0]) + getSize(u->child[1]);
    }
}

inline bool getDir(node *u, node *v) {
    return u->child[0] == v ? 0 : 1;
}

inline void connect(node *u, node *v, bool dir) {
    u->child[dir] = v;
    if (v != null) {
        v->par = u;
    }
}

node* rotate(node *u, bool dir) {
    node *c = u->child[!dir], *p = u->par, *pp = p->par;
    connect(p, c, dir);
    connect(u, p, !dir);
    connect(pp, u, getDir(pp, p));
    updSize(u), updSize(p), updSize(pp);
    return u;
}

node* splay(node *u) {
    while (u->par != null) {
        node *p = u->par, *pp = p->par;
        bool dp = getDir(p, u), dpp = getDir(pp, p);
        if (pp == null) {
            rotate(u, dp);
        } else if (dp == dpp) {
            rotate(p, dpp), rotate(u, dp);
        } else {
            rotate(u, dp), rotate(u, dpp);
        }
    }
    return u;
}

node* closest(node *u, int k) {
    if (u == null) {
        return u;
    }
    node *ans = u;
    while (u != null) {
        ans = u;
        if (u->key > k) {
            u = u->child[0];
        } else if (u->key < k) {
            u = u->child[1];
        } else {
            return u;
        }
    }
    return ans;
}

node* join(node *u, node *v) {
    if (u == null) {
        return v;
    }
    while (u->child[1] != null) {
        u = u->child[1];
    }
    splay(u);
    connect(u, v, 1);
    updSize(u);
    return u;
}

pnn split(node *u, int k) {
    if (u == null) {
        return {null, null};
    }
    u = closest(u, k);
    splay(u);
    if (u->key <= k) {
        node *v = u->child[1];
        u->child[1] = v->par = null;
        updSize(u);
        updSize(v);
        return {u, v};
    } else {
        node *v = u->child[0];
        u->child[0] = v->par = null;
        updSize(u);
        updSize(v);
        return {v, u};
    }
}

void insert(int k) {
    pnn res = split(root, k);
    if (res.first != null && res.first->key == k) {
        res.first->cnt++;
        updSize(res.first);
        root = join(res.first, res.second);
    } else {
        root = new node(k);
        root->par = null;
        connect(root, res.first, 0);
        connect(root, res.second, 1);
        updSize(root);
    }
}

void remove(int k) {
    node *u = closest(root, k);
    if (u == null) {
        return;
    }
    if (u->key != k) {
        root = splay(u);
        return;
    }
    splay(u);
    if (u->cnt > 1) {
        u->cnt--;
        updSize(u);
        root = u;
    } else if (u->cnt == 1) {
        u->child[0]->par = u->child[1]->par = null;
        root = join(u->child[0], u->child[1]);
    }
}

int valAt(int idx) {
    node *u = root;
    node *last = u;
    while (u != null) {
        last = u;
        if (getSize(u->child[0]) + u->cnt < idx) {
            idx -= getSize(u->child[0]) + u->cnt;
            u = u->child[1];
        } else if (getSize(u->child[0]) + 1 > idx) {
            u = u->child[0];
        } else {
            int ans = u->key;
            root = splay(u);
            return ans;
        }
    }
    root = splay(last);
    return INF;
}

int idxOf(int k) {
    node *u = root;
    node *last = u;
    int ans = 0;
    while (u != null) {
        last = u;
        if (u->key < k) {
            ans += getSize(u->child[0]) + u->cnt;
            u = u->child[1];
        } else if (u->key > k) {
            u = u->child[0];
        } else {
            ans += getSize(u->child[0]) + 1;
            root = splay(u);
            return ans;
        }
    }
    root = splay(last);
    return -1;
}

void traverse(node *u) {
    if (u == null) {
        return;
    }
    traverse(u->child[0]);
    for (int i = 0; i < u->cnt; i++) {
        printf("%d ", u->key);
    }
    traverse(u->child[1]);
}

int main() {
    
    scanf("%d", &Q);
    char c;
    int x;
    while (Q--) {
        scanf(" %c%d", &c, &x);
        if (c == 'I') {
            insert(x);
        } else if (c == 'R') {
            remove(x);
        } else if (c == 'S') {
            int ans = valAt(x);
            if (ans == INF) {
                printf("Invalid input\n");
            } else {
                printf("Value at %d is %d\n", x, ans);
            }
        } else if (c == 'L') {
            int ans = idxOf(x);
            if (ans == -1) {
                printf("%d not found\n", x);
            } else {
                printf("Index of %d is %d\n", x, ans);
            }
        }
    }
    
    traverse(root);
    
    return 0;
    
}

