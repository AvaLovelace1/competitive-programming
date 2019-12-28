/*
 Solution to New Year Garland by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const double EPS = 1e-9;

int T, R, G, B;

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &R, &G, &B);
        ll N = (ll) R + G + B, m = max(R, max(G, B));
        printf((m > (N - m) + 1) ? "No\n" : "Yes\n");
    }

    return 0;
}
