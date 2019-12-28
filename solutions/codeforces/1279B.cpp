/*
 Solution to Verse For Santa by Ava Pun
 Key concepts: binary search
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T, N, S;
int arr[MAX];
ll pref[MAX];

inline int binSearch(int skip) {
    int lo = 1, hi = N + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (pref[mid] - arr[skip] * (skip <= mid) > S) {
            hi = mid;
        } else { 
            lo = mid + 1;
        }
    }
    if (skip == 0 || skip > lo - 1) {
        return lo - 1;
    } else {
        return lo - 2;
    }
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &S);
        ll tot = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
            pref[i] = pref[i - 1] + arr[i];
        }

        int bestIdx = 0;
        int best = 0;
        for (int i = 0; i <= N; i++) {
            int cur = binSearch(i);
            if (cur > best) {
                best = cur, bestIdx = i;
            }
        }
        printf("%d\n", bestIdx);
    }

    return 0;
}
