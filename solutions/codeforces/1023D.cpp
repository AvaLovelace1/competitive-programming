/*
 Solution to Array Restoration by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, Q;
int arr[MAX], tree[2 * MAX], pre[MAX];

inline int query(int l, int r) {
    l += N - 1, r += N - 1;
    int ans = INF;
    while (l <= r) {
        if (l & 1) {
            ans = min(ans, tree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = min(ans, tree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int main() {
    
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        tree[i + N - 1] = arr[i] == 0 ? INF : arr[i];
    }
    for (int i = N - 1; i > 0; i--) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }
    
    for (int i = 1; i <= N; i++) {
        if (arr[i] != 0) {
            if (pre[arr[i]] != 0 && query(pre[arr[i]] + 1, i - 1) < arr[i]) {
                printf("NO\n");
                return 0;
            }
            pre[arr[i]] = i;
        }
    }
    
    int pos = -1;
    bool qFound = 0;
    arr[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) {
            arr[i] = arr[i - 1];
            pos = i;
        } else if (arr[i] == Q) {
            qFound = 1;
        }
    }
    
    if (!qFound) {
        if (pos == -1) {
            printf("NO\n");
            return 0;
        } else {
            arr[pos] = Q;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
