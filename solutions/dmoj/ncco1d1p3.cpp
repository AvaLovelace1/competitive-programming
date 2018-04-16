/*
 Solution to Mock CCO '18 Contest 1 Problem 3 - A Segment Tree Problem by Ava Pun
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

int N, M, C;
int minTree[2 * MAX], maxTree[2 * MAX];

int queryMin(int l, int r) {
    l += N - 1, r += N - 1;
    int ans = INF;
    while (l <= r) {
        if (l & 1) {
            ans = min(ans, minTree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = min(ans, minTree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int queryMax(int l, int r) {
    l += N - 1, r += N - 1;
    int ans = -1;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, maxTree[l]);
            l++;
        }
        if (!(r & 1)) {
            ans = max(ans, maxTree[r]);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ans;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &C);
    for (int i = N; i < 2 * N; i++) {
        scanf("%d", &minTree[i]);
        maxTree[i] = minTree[i];
    }
    for (int i = N - 1; i > 0; i--) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1 | 1]);
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1]);
    }
    
    bool found = false;
    for (int i = 1; i + M - 1 <= N; i++) {
        if (queryMax(i, i + M - 1) - queryMin(i, i + M - 1) <= C) {
            printf("%d\n", i);
            found = true;
        }
    }
    if (!found) {
        printf("NONE\n");
    }
    
    return 0;
}
