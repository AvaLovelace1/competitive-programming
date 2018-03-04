/*
 ~ Sieve of Eratosthenes ~
 
 Finds all prime numbers up to N.
 Used to love drawing these all the time in Grade 6 <3 it was fun to colour in the numbers ~
 
 Time complexity: O(NloglogN)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
bool sieve[MAX];

void makeSieve() {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = true;
            }
        }
    }
}

int main() {
    
    scanf("%d", &N);
    makeSieve();
    printf("Prime numbers from 1 to %d: ", N);
    for (int i = 1; i <= N; i++) {
        if (!sieve[i]) {
            printf("%d ", i);
        }
    }
    printf("\n";);
    
    return 0;
    
}
