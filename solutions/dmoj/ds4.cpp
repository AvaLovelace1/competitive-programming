/*
 Solution to Binary Search Tree Test by Ava Pun
 Key concepts: binary search tree, treap
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, Q;

struct node {
    int key, val, size, cnt, p;
    node *child[2];
    node(int k, int v) {
        key = k;
        val = v;
        size = 1;
        cnt = 1;
        p = rand();
        child[0] = child[1] = 0;
    }
    node(int k) {
        key = k;
        val = k;
        size = 1;
        cnt = 1;
        p = rand();
        child[0] = child[1] = 0;
    }
};

node *root;

inline int getSize(node *u) {
    return u ? u->size : 0;
}

inline void updSize(node *u) {
    if (u) {
        u->size = getSize(u->child[0]) + getSize(u->child[1]) + u->cnt;
    }
}

void rotate(node *&u, bool dir) {
    node *c = u->child[dir];
    u->child[dir] = c->child[!dir];
    c->child[!dir] = u;
    updSize(u), updSize(c);
    u = c;
}

void insert(node *&u, int k) {
    if (!u) {
        u = new node(k);
        return;
    }
    if (u->key == k) {
        u->cnt++;
    } else {
        bool dir = u->key < k;
        insert(u->child[dir], k);
        if (u->child[dir]->p > u->p) {
            rotate(u, dir);
        }
    }
    updSize(u);
}

void remove(node *&u, int k) {
    if (!u) {
        return;
    }
    if (u->key == k) {
        if (u->cnt > 1) {
            u->cnt--;
        } else {
            if (!u->child[0] || !u->child[1]) {
                u = u->child[0] ? u->child[0] : u->child[1];
            } else {
                bool dir = u->child[1]->p > u->child[0]->p;
                rotate(u, dir);
                remove(u->child[!dir], k);
            }
        }
    } else {
        bool dir = u->key < k;
        remove(u->child[dir], k);
    }
    updSize(u);
}

int valAt(node *u, int idx) {
    if (!u) {
        return INF;
    }
    if (getSize(u->child[0]) >= idx) {
        return valAt(u->child[0], idx);
    } else {
        if (getSize(u->child[0]) + u->cnt >= idx) {
            return u->key;
        } else {
            return valAt(u->child[1], idx - getSize(u->child[0]) - u->cnt);
        }
    }
}

int idxOf(node *u, int k) {
    if (!u) {
        return -1;
    }
    if (u->key == k) {
        return getSize(u->child[0]) + 1;
    } else {
        bool dir = u->key < k;
        int ans = idxOf(u->child[dir], k);
        return ans == -1 ? -1 : ans + (dir ? getSize(u->child[0]) + u->cnt : 0);
    }
}

void traverse(node *u) {
    if (!u) {
        return;
    }
    traverse(u->child[0]);
    for (int i = 0; i < u->cnt; i++) {
        printf("%d ", u->key);
    }
    traverse(u->child[1]);
}

int main() {
    
    scanf("%d%d", &N, &Q);
    char c;
    int x;
    while (N--) {
        scanf("%d", &x);
        insert(root, x);
    }
    int prev = 0;
    while (Q--) {
        scanf(" %c%d", &c, &x);
        x ^= prev;
        if (c == 'I') {
            insert(root, x);
        } else if (c == 'R') {
            remove(root, x);
        } else if (c == 'S') {
            int ans = valAt(root, x);
            printf("%d\n", ans);
            prev = ans;
        } else if (c == 'L') {
            int ans = idxOf(root, x);
            printf("%d\n", ans);
            prev = ans;
        }
    }
    traverse(root);
    
    return 0;
    
}
