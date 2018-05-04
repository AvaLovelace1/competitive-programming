/*
 Solution to MWC '15 #6 P2: Breadwinners by Ava Pun
 Key concepts: sieve of Eratosthenes
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

int N;
bool comp[MAX];
vi primes;

int main() {
    
    scanf("%d", &N);
    comp[1] = 1;
    for (int i = 2; i * i < MAX; i++) {
        if (!comp[i]) {
            for (int j = i * i; j < MAX; j += i) {
                comp[j] = 1;
            }
        }
    }
    for (int i = 2; i < MAX; i++) {
        if (!comp[i]) {
            primes.pb(i);
        }
    }
    
    int n;
    while (N--) {
        scanf("%d", &n);
        int idx = (int) (lower_bound(primes.begin(), primes.end(), n) - primes.begin()) - 1;
        if (idx < 0) {
            printf("no can do\n");
        } else {
            printf("%d \n", primes[idx]);
        }
    }
    
    return 0;
}
