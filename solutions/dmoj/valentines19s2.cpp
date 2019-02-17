/*
 Solution to Valentine's Day '19 S2 - Ctudor's Cute Cacti by Ava Pun
 Key concepts: 
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int N, Q;
bool row[MAX], col[MAX];
map<pii, bool> mp;

int main() {
    
    scanf("%d%d", &N, &Q);
    int t, r, c;
    while (Q--) {
        scanf("%d%d%d", &t, &r, &c);
        if (t == 1) {
            row[r] ^= 1;
            col[c] ^= 1;
            mp[{r, c}] ^= 1;
        } else {
            printf("%d\n", row[r] ^ col[c] ^ mp[{r, c}]);
        }
    }

    return 0;
}
