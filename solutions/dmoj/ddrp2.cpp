/*
 Solution to Double Doors Regional P2 - Tudor Learns DDR by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

char A, B, C;

int main() {

    scanf(" %c %c %c", &A, &B, &C);
    
    if (A != B && B != C && C != A) {
        if (A == 'U') {
            printf(C == 'D' ? "Candle\n" : "Neither\n");
        } else if (A == 'D') {
            printf(C == 'U' ? "Candle\n" : "Neither\n");
        } else if (A == 'L') {
            printf(C == 'R' ? "Crossover\n" : "Neither\n");
        } else if (A == 'R') {
            printf(C == 'L' ? "Crossover\n" : "Neither\n");
        }
    } else {
        printf("Neither\n");
    }
    
    return 0;
}
