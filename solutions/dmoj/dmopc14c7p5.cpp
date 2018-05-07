/*
 Solution to DMOPC '14 Contest 8 P5 - Aurora by Ava Pun
 Key concepts: ad hoc, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, A, B, C;
int arr[MAX];

int main() {
    
    scanf("%d%d%d%d%d", &N, &M, &A, &B, &C);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + N + 1);
    
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += min((ll) A * (arr[i] - 1) + (ll) C * (N - i), (ll) B * (arr[i] - 1));
    }
    printf("%lld\n", ans);
    
    return 0;
}
