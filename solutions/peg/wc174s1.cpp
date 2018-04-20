/*
 Solution to WC17 #4 - Wakandan Sabotage by Ava Pun
 Key concepts: graph theory
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

int N, M, K;

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    N--, M--;

    if (K >= M) {
        printf("%d\n", N * (M + 1) + M - (K - M));
    } else {
        printf("%d\n", N * K + M + N);
    }
    
    return 0;
}
