/*
 Solution to Kirito by Ava Pun
 Key concepts: segment tree
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
string arr[2005];
int tree[4005];
int indices[4005];
int lcp[2005];

int findLCP(int pos) {
    int i = 0;
    while (i < M && arr[pos + 1][i] == arr[pos][i]) {
        i++;
    }
    return i;
}

void build(int pos) {
    tree[pos] = min(min(tree[pos << 1], tree[pos << 1 | 1]), lcp[indices[pos << 1]]);
}

int query(int l, int r) {
    l += N - 1;
    r += N - 1;
    int lPos = N, rPos = N, lAns = M, rAns = M;
    while (l <= r) {
        if (l & 1) {
            //cout << "l " << l << " " << indices[l] << " " << tree[l] << " " << lPos << " " << lcp[lPos] << "\n";
            lAns = min(min(lAns, tree[l]), lcp[lPos]);
            lPos = indices[l];
            l++;
        }
        if (!(r & 1)) {
            //cout << "r " << r << " " << indices[r] << " " << tree[r] << " " << rPos << " " << lcp[rPos] << "\n";
            rAns = min(min(rAns, tree[r]), lcp[rPos]);
            rPos = indices[r - 1];
            r--;
        }
        l >>= 1, r >>= 1;
    }
    //cout << lAns << " " << rAns << " " << lPos << " " << lcp[lPos] << "\n";
    return min(min(lAns, rAns), lPos == rPos ? lcp[lPos] : INT_MAX);
}

void update(int pos) {
    if (pos < 1 || pos >= N) {
        return;
    }
    lcp[pos] = findLCP(pos);
    pos += N - 1;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        build(i);
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i < N; i++) {
        lcp[i] = findLCP(i);
    }
    lcp[N] = M;
    
    for (int i = 1; i <= N; i++) {
        indices[i + N - 1] = i;
        tree[i + N - 1] = M;
    }
    
    for (int i = N - 1; i > 0; i--) {
        indices[i] = indices[i << 1 | 1];
        build(i);
    }
    
    cin >> Q;
    int a, b;
    while (Q--) {
        cin >> a >> b;
        cout << query(a, b) * (b - a + 1) << "\n";
        swap(arr[a], arr[b]);
        update(a - 1), update(a), update(b - 1), update(b);
    }

    return 0;
}
