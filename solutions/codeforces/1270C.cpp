/*
 Solution to Make Good by Ava Pun
 Key concepts: mathematics
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
const double EPS = 1e-9;

int T, N;
int arr[MAX];

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        ll sum = 0, xo = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
            xo ^= arr[i];
        }
        ll x1 = xo;
        sum += x1, xo ^= x1;
        ll x2 = sum;
        sum += x2, xo ^= x2;
        printf("2\n");
        printf("%lld %lld\n", x1, x2);
        //assert(sum == 2 * xo);
    }

    return 0;
}
