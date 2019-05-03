/*
 Solution to DMOPC '18 Contest 6 P1 - DNA or RNA? by Ava Pun
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
const int MAX = 1e6 + 5;

int N;
const char VALID[] = {'A', 'G', 'C', 'T', 'U'};

int main() {
    
    scanf("%d", &N);
    char c;
    bool T = 0, U = 0;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        bool v = 0;
        for (int j = 0; j < 5; j++) {
            if (c == VALID[j]) {
                v = 1;
                break;
            }
        }
        if (!v) {
            printf("neither\n");
            return 0;
        }
        if (c == 'T') {
            T = 1;
        } else if (c == 'U') {
            U = 1;
        }
    }
    if (T) {
        printf(U ? "neither\n" : "DNA\n");
    } else {
        printf(U ? "RNA\n" : "both\n");
    }
    
    return 0;
}
