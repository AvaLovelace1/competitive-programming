/*
 Solution to WC17 #3 - Down for Maintenance by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, bool> pii;
typedef pair<pii, bool> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int I, N, M, K;
ll arr[2 * MAX];
unordered_map<ll, bool> on;

int main() {
    
    scanf("%d%d", &I, &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
        on[arr[i]] = 1;
    }
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%lld", &arr[i + N]);
        on[arr[i + N]] = 0;
    }
    sort(arr + 1, arr + N + M + 1);
    
    bool pre = 1;
    int cnt = 0;
    for (int i = 1; i <= N + M; i++) {
        if (!on[arr[i]] && pre) {
            cnt++;
        }
        pre = on[arr[i]];
    }
    if (N != 0 && !on[arr[1]] && !on[arr[N + M]]) {
        cnt--;
    }
    
    if (I < cnt) {
        printf("Impossible\n");
    } else {
        scanf("%d", &K);
        ll n;
        while (K--) {
            scanf("%lld", &n);
            int r = (int) (lower_bound(arr + 1, arr + N + M + 1, n) - arr);
            int l = r - 1;
            if (r > N + M) {
                r = 1;
            }
            if (l < 1) {
                l = N + M;
            }
            if (N == 0 && M == 0) {
                printf("Unknown\n");
            } else if (arr[r] == n) {
                printf(on[arr[r]] ? "Up\n" : "Down\n");
            } else if (N == 0 || M == 0) {
                printf("Unknown\n");
            } else if (I == cnt) {
                if (on[arr[l]] == on[arr[r]]) {
                    printf(on[arr[r]] ? "Up\n" : "Down\n");
                } else {
                    printf("Unknown\n");
                }
            } else {
                printf("Unknown\n");
            }
        }
    }
    
    return 0;
}
