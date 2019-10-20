/*
 Solution to Nearly prime numbers by Ava Pun
 Key concepts: math, implementation, brute force
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

int N, K;

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
         if (n % i == 0) {
             return 0;
         }
    } 
    return 1;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &K);
        bool ans = 0;
        for (int j = 2; j * j <= K; j++) {
            if (K % j == 0) {
                if (prime(j) && prime(K / j)) {
                    ans = 1;
                }
                break;
            }
        }
        printf(ans ? "Yes\n" : "No\n");
    }

    return 0;
}
