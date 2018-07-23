/*
 Solution to TLE '17 Contest 4 P6 - Fax's Christmas Bash by Ava Pun
 Key concepts: calculus, binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<piii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 5;
const int MAXX = 3e4 + 5;

int N;
bool counted[MAXX + 1];
ll bit[3][MAXX + 1], totSum[3];

inline void update(int pos, ll x, int idx) {
    totSum[idx] += x;
    for (int i = pos; i <= MAXX; i += i & -i) {
        bit[idx][i] += x;
    }
}

inline ll query(int pos, ll bit[]) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline void update(int x) {
    int pos = x + 15001;
    update(pos, 1, 0);
    update(pos, x, 1);
    update(pos, x * x, 2);
}

inline double slope(double x) {
    int x1 = (int) floor(x) + 15001;
    ll n1 = query(x1, bit[0]), n2 = totSum[0] - n1;
    ll s1 = query(x1, bit[1]), s2 = totSum[1] - s1;
    ll sSq1 = query(x1, bit[2]), sSq2 = totSum[2] - sSq1;
    return 3 * (n1 - n2) * x * x + 6 * (s2 - s1) * x + 3 * (sSq1 - sSq2);
}   

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        update(n);
        double lo = -15000, hi = 15000, mid;
        while (hi - lo > 1e-4) {
            mid = (lo + hi) / 2;
            if (slope(mid) >= 0) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        printf("%lf\n", lo);
    }
    
    return 0;
}
