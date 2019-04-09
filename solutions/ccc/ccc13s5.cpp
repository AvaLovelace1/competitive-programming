/*
 Solution to CCC '13 S5 - Factor Solitaire by Ava Pun
 Key concepts: greedy algorithms, mathematics
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 5e6 + 5;

int N;
int spf[MAX];

int main() {

    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (ll j = (ll) i * i; j <= N; j += i) {
                spf[j] = i;
            } 
        }
    }

    ll ans = 0;
    while (N > 1) {
        int m = N / spf[N];
        N -= m;
        ans += N / m;
    }
    printf("%lld\n", ans);

    return 0;
}
