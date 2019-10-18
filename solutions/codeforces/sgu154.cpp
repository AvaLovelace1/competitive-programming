/*
 Solution to Factorial by Ava Pun
 Key concepts: math, binary search
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
const double EPS = 1e-9;

int Q;

inline int zeros(int n) {
    int b = 5, ret = 0;
    for (int i = 1; b <= n; i++) {
        ret += n / b;
        b *= 5;
    }
    return ret;
}

int main() {

    scanf("%d", &Q);
    int lo = 1, hi = 5 * Q, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (zeros(mid) >= Q) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (zeros(lo) == Q) {
        printf("%d\n", lo);
    } else {
        printf("No solution\n");
    }

    return 0;
}
