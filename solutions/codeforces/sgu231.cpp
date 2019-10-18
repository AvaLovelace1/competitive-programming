/*
 Solution to Prime Sum by Ava Pun
 Key concepts: sieve of Eratosthenes, math, implementation
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
const int MAX = 1e6 + 5;
const double EPS = 1e-9;

int N;
bool sieve[MAX];

int main() {

    scanf("%d", &N);
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i * i <= N; i++) {
        if (!sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = 1;
            }
        }
    }
    vii ans;
    for (int i = 2; i <= N - 2; i++) {
        if (!sieve[i] && !sieve[i + 2]) {
            ans.pb({2, i});
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.f, p.s);
    }

    return 0;
}
