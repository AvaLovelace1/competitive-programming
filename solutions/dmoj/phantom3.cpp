/*
 Solution to The Torture Chamber by Ava Pun
 Key concepts: sieve of Eratosthenes
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll N, M;

bool sieve1[100005], sieve2[20000005];

int main() {
    
    scanf("%lld%lld", &N, &M);
    int upper = (int) sqrt(M - 1);
    sieve1[0] = sieve1[1] = 1;
    
    int count = 0;
    if (N == 1) {
        sieve2[0] = 1;
        count++;
    } else if (N == 0) {
        sieve2[0] = sieve2[1] = 1;
        count += 2;
    }
    
    for (ll i = 2; i <= upper; i++) {
        if (!sieve1[i]) {
            for (ll j = i * i; j <= upper; j += i) {
                sieve1[j] = 1;
            }
            for (ll j = N / i * i; j < M; j += i) {
                if (j >= N && j != i && !sieve2[j - N]) {
                        sieve2[j - N] = 1;
                        count++;
                }
            }
        }
    }
    
    printf("%lld", M - N - count);
    
    return 0;
    
}
