/*
 Solution to WC18 #1 - Bad Influence by Ava Pun
 Key concepts: segment tree, binary indexed tree
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
const int MAX = 3e5 + 5;
const int MAX2 = 1e6 + 5;

int N;
int N1 = 1000001;
int arr[MAX];
int S[MAX], D[MAX], R[MAX];
int tree[2 * MAX2];
int covered[MAX];
int bit[MAX2];

inline bool comp(int a, int b) {
    return S[a] > S[b];
}

inline void upd(int l, int r, int x) {
    l += N1 - 1, r += N1 - 1;
    while (l <= r) {
        if (l & 1) {
            tree[l] = min(tree[l], x);
            l++;
        }
        if (!(r & 1)) {
            tree[r] = min(tree[r], x);
            r--;
        }
        l >>= 1, r >>= 1;
    }
}

inline int quer(int pos) {
    pos += N1 - 1;
    int ans = INF;
    for (int i = pos; i > 0; i >>= 1) {
        ans = min(ans, tree[i]);
    }
    return ans;
}

inline void updBit(int pos, int x) {
    for (int i = pos; i <= N1; i += i & -i) {
        bit[i] += x;
    }
}

inline int querBit(int pos) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &S[i], &D[i], &R[i]);
        arr[i] = i;
    }
    sort(arr + 1, arr + N + 1, comp);
    
    fill(tree, tree + 2 * N1 + 1, N1);
    for (int i = 1; i <= N; i++) {
        covered[arr[i]] = quer(D[arr[i]]);
        upd(max(1, D[arr[i]] - R[arr[i]]), min(N1, D[arr[i]] + R[arr[i]]), arr[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        updBit(covered[i], 1);
        printf("%d\n", i - querBit(i));
    }
    
    return 0;
}
