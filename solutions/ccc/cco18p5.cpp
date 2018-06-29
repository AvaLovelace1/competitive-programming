/*
 Solution to CCO '18 P5 - Boring Lectures by Ava Pun
 Key concepts: segment tree
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
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, K, Q;
int arr[MAX];
int maxTree[2 * MAX], locTree[2 * MAX];
deque<pii> q;
int maxes[2 * MAX];

inline bool comp(int a, int b) {
    if (a == 0) {
        return 1;
    } else if (b == 0) {
        return 0;
    } else if (arr[a] == arr[b]) {
        return a < b;
    } else {
        return arr[a] < arr[b];
    }
}

inline void updMax(int pos, int x) {
    arr[pos] = x;
    pos += N - 1;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1], comp);
    }
}

inline void updLoc(int pos, int x) {
    pos += N - 1;
    locTree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        locTree[i] = max(locTree[i << 1], locTree[i << 1 | 1]);
    }
}

inline int query(int l, int r) {
    l = max(l, 1), r = min(r, N);
    l += N - 1, r += N - 1;
    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, maxTree[l], comp);
            l++;
        }
        if (!(r & 1)) {
            ans = max(ans, maxTree[r], comp);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

inline pii maxLR(int i) {
    return {query(i - K + 1, i - 1), query(i + 1, i + K - 1)};
}

inline void checkLoc(int i) {
    pii lr = maxLR(i);
    if (arr[i] >= arr[lr.f] && arr[i] > arr[lr.s]) {
        updLoc(i, arr[i] + max(arr[lr.f], arr[lr.s]));
    }
}

int main() {
    
    scanf("%d%d%d", &N, &K, &Q);
    arr[0] = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        maxTree[i + N - 1] = i;
    }
    for (int i = N - 1; i > 0; i--) {
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1], comp);
    }
    for (int i = 1; i <= N + K - 1; i++) {
        if (!q.empty() && q.front().s == i - K + 1) {
            q.pop_front();
        }
        if (i <= N) {
            while (!q.empty() && q.back().f <= arr[i]) {
                q.pop_back();
            }
            q.push_back({arr[i], i});
        }
        maxes[i] = q.front().s;
    }
    for (int i = 1; i <= N; i++) {
        pii lr = {i == 1 ? 0 : maxes[i - 1], i == N ? 0 : maxes[i + K - 1]};
        if (arr[i] >= arr[lr.f] && arr[i] > arr[lr.s]) {
            locTree[i + N - 1] = arr[i] + max(arr[lr.f], arr[lr.s]);
        }
    }
    for (int i = N - 1; i > 0; i--) {
        locTree[i] = max(locTree[i << 1], locTree[i << 1 | 1]);
    }

    int ans = locTree[1];
    printf("%d\n", ans);
    
    int i, x;
    while (Q--) {
        scanf("%d%d", &i, &x);
        i ^= ans, x ^= ans;
        updMax(i, x);
        pii lr = maxLR(i);
        if (x >= arr[lr.f] && x > arr[lr.s]) {
            updLoc(i, x + max(arr[lr.f], arr[lr.s]));
        } else {
            updLoc(i, 0);
            if (lr.f != 0) {
                checkLoc(lr.f);
            }
            if (lr.s != 0) {
                checkLoc(lr.s);
            }
        }
        ans = locTree[1];
        printf("%d\n", ans);
    }
    
    return 0;
}
