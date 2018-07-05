/*
 Solution to World Domination Fun by Ava Pun
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

int N, M, K;
ll arr[MAX], tmp[MAX];

bool check(ll n) {
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
        tmp[i] = arr[i] - arr[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        tmp[i] += tmp[i - 1];
        if (tmp[i] < n) {
            ll d = n - tmp[i];
            cnt += d;
            tmp[i] += d, tmp[min(N + 1, i + M)] -= d;
        }
        
    }
    return cnt <= K;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
    }
    
    ll lo = 1, hi = 2e9 + 1;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    printf("%lld\n", lo - 1);
    
    return 0;
}
