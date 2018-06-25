/*
 Solution to 11498 - Division of Nlogonia by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int K, N, M, X, Y;

int main() {
    
    scanf("%d", &K);
    while (K) {
        scanf("%d%d", &N, &M);
        while (K--) {
            scanf("%d%d", &X, &Y);
            X -= N, Y -= M;
            if (X == 0 || Y == 0) {
                printf("divisa\n");
            } else {
                printf("%c%c\n", Y > 0 ? 'N' : 'S', X > 0 ? 'E' : 'O');
            }
        }
        scanf("%d", &K);
    }
    
    return 0;
}
