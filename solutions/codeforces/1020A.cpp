/*
 Solution to New Building for SIS by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, H, A, B, Q;

int main() {
    
    scanf("%d%d%d%d%d", &N, &H, &A, &B, &Q);
    int ta, fa, tb, fb;
    while (Q--) {
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        int fl;
        if (fa > B) {
            fl = B;
        } else if (fa < A) {
            fl = A;
        } else {
            fl = fa;
        }
        if (tb != ta) {
            printf("%d\n", abs(tb - ta) + abs(fa - fl) + abs(fb - fl));
        } else {
            printf("%d\n", abs(fb - fa));
        }
    }
    
    return 0;
}
