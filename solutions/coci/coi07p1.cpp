/*
 Solution to  by Ava Pun
 Key concepts: binary search, greedy algorithms
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

double K;
int N;
double arr[MAX];

bool good(double x) {
    double dist = arr[1] + x;
    for (int i = 2; i <= N; i++) {
        if (arr[i] - x > dist + K) {
            return 0;
        } else {
            dist = min(dist + K, arr[i] + x);
        }
    }
    return 1;
}

int main() {
    
    scanf("%lf%d", &K, &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lf", &arr[i]);
    }
    
    double lo = 0, hi = 1e9, mid;
    for (int i = 1; i <= 100; i++) {
        mid = (lo + hi) / 2;
        if (good(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%lf\n", lo);

    return 0;
}
