/*
 Solution to DMOPC '18 Contest 5 P2 - A Photography Problem by Ava Pun
 Key concepts: binary search
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef double ld;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int N, M;
ld arr[MAX][MAX];

ld check(ld c) {
    ld avg = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            avg += min(1.0, arr[i][j] * c);
        }
    }
    avg /= N * M;
    return avg;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
    
    ld lo = 0, hi = 480, mid;
    for (int i = 1; i <= 50; i++) {
        mid = (lo + hi) / 2;
        if (check(mid) >= 0.48) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    assert(abs(check(lo) - 0.48) <= 1e-9);
    if (abs(lo - 1) <= 1e-5) {
        printf("correctly exposed\n");
    } else {
        printf(lo > 1 ? "underexposed\n" : "overexposed\n");
        printf("%.9lf\n", lo);
        assert(abs(lo - 1) >= 1e-4);
    }
    
    return 0;
}
