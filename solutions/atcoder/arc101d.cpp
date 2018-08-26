/*
 Solution to Median of Medians by Ava Pun
 Key concepts: binary search, binary indexed tree
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
const int MAX = 1e5 + 5;

int N;
int arr[MAX], sorted[MAX], pref[MAX], bit[2 * MAX];

inline void update(int pos, int x) {
    pos += N + 1;
    for (int i = pos; i <= 2 * N + 1; i += i & -i) {
        bit[i] += x;
    }
}

inline int query(int pos) {
    pos += N + 1;
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline bool check(int x) {
    
    FILL(pref, 0), FILL(bit, 0);
    for (int i = 1; i <= N; i++) {
        pref[i] = arr[i] >= x ? 1 : -1;
        pref[i] += pref[i - 1];
    }
    
    ll ans = 0;
    update(0, 1);
    for (int i = 1; i <= N; i++) {
        ans += query(pref[i]);
        update(pref[i], 1);
    }
    return ans >= ((ll) N * (N - 1) / 2 + N + 1) / 2;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }
    sort(sorted + 1, sorted + N + 1);
    
    int lo = 2, hi = N + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (!check(sorted[mid])) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", sorted[lo - 1]);
    
    return 0;
}
