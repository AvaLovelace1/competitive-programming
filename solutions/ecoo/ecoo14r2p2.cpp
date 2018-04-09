/*
 Solution to ECOO '14 R2 P2 - Black and Grey by Ava Pun
 Key concepts: implementation, simple math
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
const int MAX = 1e5 + 5;

int N, R, C;
set<int> facts;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        facts.clear();
        scanf("%d", &N);
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                facts.insert(i), facts.insert(N / i);
            }
        }
        for (int i = 1; i <= 5; i++) {
            scanf("%d%d", &R, &C);
            R--, C--;
            bool flip = 0;
            for (int j : facts) {
                if (C / j % 2 == 0) {
                    flip ^= !(R / j % 2);
                } else {
                    flip ^= R / j % 2;
                }
            }
            printf("%c", flip ? 'B' : 'G');
        }
        printf("\n");
    }
    
    return 0;
}
