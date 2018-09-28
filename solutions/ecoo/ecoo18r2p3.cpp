/*
 Solution to ECOO '18 R2 P3 - Factorial by Ava Pun
 Key concepts: binary search, math
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

int K, M;
vector<pii> facts;

bool check(ll n) {
    for (auto p : facts) {
        ll cnt = 0;
        for (ll i = p.f; i <= n; i *= p.f) {
            cnt += n / i;
        }
        if (cnt < (ll) p.s * M) {
            return 0;
        }
    } 
    return 1;
}

int main() {
    
    for (int test = 1; test <= 10; test++) {

        facts.clear();
        scanf("%d%d", &K, &M);
        int k = K;
        for (int i = 2; i <= K; i++) {
            int cnt = 0;
            while (k % i == 0) {
                k /= i;
                cnt++;
            }
            if (cnt != 0) {
                facts.pb({i, cnt});
            }
        }

        ll lo = 0, hi = INFL, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        printf("%lld\n", lo);
    }
    
    return 0;
}
