/*
 Solution to Border by Ava Pun
 Key concepts: math
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

int N, K;

int main() {
    
    scanf("%d%d", &N, &K);
    int n, gcd = K;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        if (n % K != 0) {
            gcd = __gcd(gcd, n % K);
        }
    }
    printf("%d\n", K / gcd);
    for (int i = 0; i < K; i += gcd) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
