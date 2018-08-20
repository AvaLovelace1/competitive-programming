/*
 Solution to Numbers on the Chessboard by Ava Pun
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
const int MAX = 100 + 5;

ll N, Q;

int main() {
    
    scanf("%lld%lld", &N, &Q);
    ll n = (N * N + 1) / 2, r, c;
    while (Q--) {
        scanf("%lld%lld", &r, &c);
        ll k = ((r - 1) * N + c + 1) / 2;
        if ((r + c) % 2 == 0) {
            printf("%lld\n", k);
        } else {
            printf("%lld\n", k + n);
        }
    }
    
    return 0;
}
