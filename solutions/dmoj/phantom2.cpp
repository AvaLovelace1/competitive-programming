/*
 Solution to The Third Cellar by Ava Pun
 Key concepts: sieve of Eratosthenes
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
const int MOD = 1e9 + 7;
const int MAX = 1e6;

int N;
bool prime[MAX + 5];

int main() {
    
    FILL(prime, 1);
    prime[0] = prime[1] = 0;
    
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = 0;
            }
        }
    }

    scanf("%d", &N);
    int l, r;
    while (N--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", accumulate(prime + l, prime + r, 0));
    }
    
    return 0;
}
