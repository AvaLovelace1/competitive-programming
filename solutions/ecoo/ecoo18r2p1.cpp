/*
 Solution to ECOO '18 R2 P1 - Artificial Photosynthesystem by Ava Pun
 Key concepts: implementation, simulation
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
const int MAX = 1e5 + 5;

int C, O, W, S, Ci, Wi, So, Oo, Si, Oi, Co, Wo;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        scanf("%d%d%d%d", &C, &O, &W, &S);
        scanf("%d%d%d%d", &Ci, &Wi, &So, &Oo);
        scanf("%d%d%d%d", &Si, &Oi, &Co, &Wo);
        
        int maxO = O;
        bool done = 0;
        while (!done) {
            done = 1;
            while (C >= Ci && W >= Wi) {
                C -= Ci, W -= Wi;
                S += So, O += Oo;
                done = 0;
            }
            maxO = max(O, maxO);
            while (S >= Si && O >= Oi) {
                S -= Si, O -= Oi;
                C += Co, W += Wo;
                done = 0;
            }
            maxO = max(O, maxO);
        }
        printf("%d\n", maxO);
    }
    
    return 0;
}
