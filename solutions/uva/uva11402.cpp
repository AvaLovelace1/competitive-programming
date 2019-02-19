/*
 Solution to 11402 - Ahoy, Pirates! by Ava Pun
 Key concepts: segment tree with lazy propagation
 */

#include <bits/stdc++.h>

using namespace std;

#define FILL(a, b) memset(a, b, sizeof(a))

const int MAX = 1024000 + 5;

int T;
int N, M, K, Q;
int h;
int tree[2 * MAX], sz[2 * MAX];
int lazy1[MAX], lazy2[MAX];

inline void apply(int pos, bool t, int x) {
    if (!t) {
        tree[pos] = x * sz[pos];
        if (pos < N) {
            lazy1[pos] = x;
            lazy2[pos] = 0;
        }
    } else {
        if (x & 1) {
            tree[pos] = sz[pos] - tree[pos];
        }
        if (pos < N) {
            lazy2[pos] += x;
            if (lazy1[pos] != -1) {
                lazy2[pos] = 0;
                lazy1[pos] ^= (x & 1);
            }
        }
    }
}

inline void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
        if (lazy1[i] != -1) {
            tree[i] = sz[i] * lazy1[i];
        }
        if (lazy2[i] & 1) {
            tree[i] = sz[i] - tree[i];
        }
    }
}

inline void down(int pos) {
    for (int k = h; k > 0; k--) {
        int i = pos >> k;
        if (lazy1[i] != -1) {
            apply(i << 1, 0, lazy1[i]);
            apply(i << 1 | 1, 0, lazy1[i]);
            lazy1[i] = -1;
        }
        if (lazy2[i]) {
            apply(i << 1, 1, lazy2[i]);
            apply(i << 1 | 1, 1, lazy2[i]);
            lazy2[i] = 0;
        }
    }
}

inline void update(int l, int r, bool t, int x) {
    l += N, r += N;
    int l0 = l, r0 = r;
    down(l0), down(r0);
    while (l <= r) {
        if (l & 1) {
            apply(l, t, x);
            l++;
        }
        if (!(r & 1)) {
            apply(r, t, x);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    up(l0), up(r0);
}

inline int query(int l, int r) {
    l += N, r += N;
    down(l), down(r);
    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += tree[l];
            l++;
        }
        if (!(r & 1)) {
            ans += tree[r];
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int main() {
    
    srand((unsigned int) time(0));
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int i = 1; i <= T; i++) {
        
        cout << "Case " << i << ":\n";
        FILL(lazy1, -1);
        FILL(lazy2, 0);
        
        N = 0;
        cin >> M;
        string pirates = "", str;
        while (M--) {
            cin >> K;
            cin >> str;
            while (K--) {
                pirates += str;
            }
        }
        N = (int) pirates.length();
        h = sizeof(int) * 8 - __builtin_clz(N);
        for (int i = 0; i < N; i++) {
            tree[i + N] = pirates[i] == '1';
            sz[i + N] = 1;
        }
        for (int i = N - 1; i > 0; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
            sz[i] = sz[i << 1] + sz[i << 1 | 1];
        }
        
        cin >> Q;
        int l, r;
        int qCnt = 0;
        while (Q--) {
            cin >> str >> l >> r;
            if (str == "F") {
                update(l, r, 0, 1);
            } else if (str == "E") {
                update(l, r, 0, 0);
            } else if (str == "I") {
                update(l, r, 1, 1);
            } else {
                qCnt++;
                cout << "Q" << qCnt << ": " << query(l, r) << '\n';
                
            }
        }
    }
    
    return 0;
}
