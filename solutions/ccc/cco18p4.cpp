/*
 Solution to CCO '18 P4 - Gradient Descent by Ava Pun
 Key concepts: binary search
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
const int MAX = 2e6 + 5;

int R, C, K;

int query(int r, int c) {
    printf("? %d %d\n", r, c);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main() {
    
    scanf("%d%d%d", &R, &C, &K);
    
    int loR = 1, hiR = R, loC = 1, hiC = C;
    while (loR < hiR || loC < hiC) {
        int midR1 = (loR + hiR) / 2, midR2 = min(hiR, midR1 + 1);
        int midC1 = (loC + hiC) / 2, midC2 = min(hiC, midC1 + 1);
        int x = query(midR1, midC1), xR = query(midR2, midC1), xC = query(midR1, midC2);
        if (x <= xR) {
            hiR = midR1;
        } else {
            loR = midR2;
        }
        if (x <= xC) {
            hiC = midC1;
        } else {
            loC = midC2;
        }
    }
    
    printf("! %d\n", query(loR, loC));
    fflush(stdout);
    
    return 0;
}
