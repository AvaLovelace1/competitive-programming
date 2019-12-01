/*
 Solution to Little Rooks by Ava Pun
 Key concepts: mathematics, combinatorics
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
const int MAX = 2e5 + 5;
const double EPS = 1e-9;

int N, K;

ll fact(int n) {
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

ll choose(int n, int k) {
    return fact(n) / fact(n-k) / fact(k);
}

int main() {

    scanf("%d%d", &N, &K);
    if (K > N) {
        printf("0\n");
    } else {
        printf("%lld\n", choose(N, K) * choose(N, K) * fact(K));
    }

    return 0;
}
