/*
 Solution to DMOPC '18 Contest 4 P1 - Dr. Henri and Differential Photometry by Ava Pun
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
const int MAX = 1005;

int K;
double mX;
double vals[MAX];

int main() {
    
    scanf("%d%lf", &K, &mX);
    int n;
    double x;
    for (int i = 1; i <= K; i++) {
        scanf("%d", &n);
        vals[i] = mX;
        while (n--) {
            scanf("%lf", &x);
            vals[i] += x;
        }
    }

    double avg = accumulate(vals + 1, vals + K + 1, 0.0) / K;

    printf("%lf\n", avg);
    
    return 0;
}
