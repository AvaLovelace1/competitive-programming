/*
 ~ Prefix Sum Array / Difference Array Data Structure ~
 
 Supports offline range updates and range queries.
 The opposite of each other, kind of.
 Has many parallels with integration/differentiation. It's really cool!
 Also can be extended to an arbitrary number of dimensions.
 
 Prefix Sum Array
 Time complexity:
 Preprocessing - O(N)
 Range query - O(1)
 
 Difference Array
 Time complexity:
 Range update - O(1)
 Postprocessing - O(N)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, Q;
int arr[MAX], pref[MAX], diff[MAX];

void buildPref(int arr[], int pref[]) {
    // note that this assumes 1-indexing
    pref[0] = 0;
    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }
}

int query(int l, int r) {
    return pref[r] - pref[l - 1];
}

void buildDiff() {
    for (int i = 1; i <= N; i++) {
        diff[i] = arr[i] - arr[i - 1];
    }
}

void updateDiff(int l, int r, int x) {
    diff[l] += x;
    diff[r + 1] -= x;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Range updates with difference array
    buildDiff();
    int a, b, c;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d%d", &a, &b, &c);
        updateDiff(a, b, c);
    }
    
    buildPref(diff, arr);
    printf("Array after updates:\n");
    for (int i = 1; i <= N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Range queries with prefix sum array
    buildPref(arr, pref);
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &a, &b);
        printf("Sum from %d to %d: %d\n", a, b, query(a, b));
    }
    
    return 0;
    
}
