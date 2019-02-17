/*
 Solution to WC18 #3 - The Perfect Team by Ava Pun
 Key concepts: implementation
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

int N, M, K;
pii arr[MAX];
int maxN[MAX];
bool chosen[MAX];

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    int a, b;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &a, &b);
        arr[i] = {b, a};
        maxN[a] = max(maxN[a], b);
    }
    sort(arr + 1, arr + N + 1, greater<pii>());
    ll ans = 0;
    for (int i = 1; i <= K; i++) {
        ans += maxN[i];
    }
    int idx = 1;
    for (int i = K + 1; i <= M; i++) {
        if (!chosen[arr[idx].s]) {
            chosen[arr[idx].s] = 1;
            i--;
        } else {
            ans += arr[idx].f;
        }
        idx++;
    }
    printf("%lld\n", ans);
    
    return 0;
}
