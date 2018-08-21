/*
 Solution to Pair of Toys by Ava Pun
 Key concepts: implementation, simple math
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

ll N, K;

int main() {

    scanf("%lld%lld", &N, &K);
    ll lo = K / 2, hi = (K + 1) / 2;
    if (lo == hi) {
        lo--, hi++;
    }
    printf("%lld\n", max(0LL, min(N - hi + 1, lo)));
    
    return 0;
}
