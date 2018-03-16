/*
 Solution to CCO '16 P6 - Pirates by Ava Pun
 Key concepts: binary search tree, dynamic programming, treap
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<char, pii> piii;
typedef vector<int> vi;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
ll K;
int arr[MAX];
ll cnt = 0;

struct node {
    ll key, sum;
    int size, cnt, p;
    node *child[2];
    node(ll k, int n) {
        key = k;
        sum = k * n;
        size = cnt = n;
        p = rand();
        child[0] = child[1] = 0;
    }
};

node *root;

inline int getSize(node *u) {
    return u ? u->size : 0;
}

inline ll getSum(node *u) {
    return u ? u->sum : 0;
}

inline void updSize(node *u) {
    if (u) {
        u->size = getSize(u->child[0]) + getSize(u->child[1]) + u->cnt;
        u->sum = getSum(u->child[0]) + getSum(u->child[1]) + u->key * u->cnt;
    }
}

void rotate(node *&u, bool dir) {
    node *c = u->child[dir];
    u->child[dir] = c->child[!dir];
    c->child[!dir] = u;
    updSize(u), updSize(c);
    u = c;
}

void insert(node *&u, ll k, int n) {
    if (!n) {
        return;
    }
    if (!u) {
        u = new node(k, n);
        return;
    }
    if (u->key == k) {
        u->cnt += n;
        u->sum += k * n;
    } else {
        bool dir = u->key < k;
        insert(u->child[dir], k, n);
        if (u->child[dir]->p > u->p) {
            rotate(u, dir);
        }
    }
    updSize(u);
}

ll query(node *u, int n) {
    if (!u) {
        return 0;
    }
    if (getSize(u->child[0]) >= n) {
        return query(u->child[0], n);
    } else if (getSize(u->child[0]) + u->cnt >= n) {
        return getSum(u->child[0]) + u->key * (n - getSize(u->child[0]));
    } else {
        return getSum(u->child[0]) + u->key * u->cnt + query(u->child[1], n - getSize(u->child[0]) - u->cnt);
    }
}

node* remove(node *&u, int n) {
    if (!u) {
        return 0;
    }
    if (getSize(u->child[0]) >= n) {
        u = remove(u->child[0], n);
    } else if (getSize(u->child[0]) + u->cnt >= n) {
        u->cnt = n - getSize(u->child[0]);
        u->child[1] = 0;
    } else {
        u->child[1] = remove(u->child[1], n - getSize(u->child[0]) - u->cnt);
    }
    updSize(u);
    return u;
}

int main() {
    
    scanf("%d%lld", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        ll ans;
        int neededV = arr[i] - 1;
        if (neededV == 0) {
            ans = K;
            root = 0;
            insert(root, 0 - cnt, i - 1);
        } else {
            ll neededC = query(root, neededV) + neededV * (cnt + 1);
            if (neededC > K) {
                ans = -1;
            } else {
                ans = K - neededC;
                cnt++;
                root = remove(root, neededV);
                insert(root, 0 - cnt, i - 1 - neededV);
            }
        }
        insert(root, ans - cnt, 1);
        printf("%lld\n", ans);
    }
    
    return 0;
    
}
