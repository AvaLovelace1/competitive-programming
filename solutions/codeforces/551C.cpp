/*
 Solution to GukiZ hates Boxes by Ava Pun
 Key concepts: binary search, greedy algorithms
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
const int MAX = 1e5 + 5;

int N, M;
int arr[MAX], tmp[MAX];

bool check(ll n) {
    
    for (int i = 1; i <= N; i++) {
        tmp[i] = arr[i];
    }
    
    int idx = N;
    for (int i = 1; i <= M; i++) {
        while (!tmp[idx] && idx > 0) {
            idx--;
        }
        ll t = n - idx;
        while (t > 0 && idx > 0) {
            if (tmp[idx]) {
                ll t1 = min((ll) tmp[idx], t);
                tmp[idx] -= t1, t -= t1;
            } else {
                idx--;
            }
        }
    }
    
    return accumulate(tmp + 1, tmp + N + 1, 0LL) == 0;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    ll lo = 1, hi = accumulate(arr + 1, arr + N + 1, 0LL) + N + 5, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    printf("%lld\n", lo);
    
    return 0;
}
