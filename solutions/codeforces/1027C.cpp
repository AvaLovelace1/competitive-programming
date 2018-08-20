/*
 Solution to Minimum Value Rectangle by Ava Pun
 Key concepts: greedy algorithms
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
const int MAX = 100 + 5;

int T, N;
bool chosen[10005];
vi v;

int main() {
    
    scanf("%d", &T);
    
    double best;
    int best1 = 0, best2 = 0;
    while (T--) {
        
        best = INFL;
        FILL(chosen, 0);
        v.clear();
        scanf("%d", &N);
        int n;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &n);
            if (chosen[n]) {
                v.pb(n);
            }
            chosen[n] ^= 1;
        }
        
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            int a = v[i], b = v[i + 1];
            double val = (pow(2.0 * (a + b), 2)) / ((double) a * b);
            if (val < best) {
                best = val;
                best1 = a, best2 = b;
            }
        }
        printf("%d %d %d %d\n", best1, best1, best2, best2);
    }
    
    return 0;
}
