/*
 Solution to APIO '19 P1 - Strange Device by Ava Pun
 Key concepts: mathematics
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<char, char> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 5005;

int Q;
ll A, B;
vector<pair<ll, bool>> events;

int main() {

    scanf("%d%lld%lld", &Q, &A, &B);
    __int128 k = A / __gcd(B + 1, A) * B;
    if (k > 1e18) {
        k = 1e18;
    }
    ll l, r;
    for (int i = 1; i <= Q; i++) {
        scanf("%lld%lld", &l, &r);
        if (r - l + 1 >= k) {
            events.pb({0, 1});
            events.pb({k, 0});
        } else {
            l %= k;
            r = (r + 1) % k;
            events.pb({l, 1});
            events.pb({r, 0});
            if (l > r) {
                events.pb({0, 1});
                events.pb({k, 0});
            }
        }
    }
    sort(events.begin(), events.end());

    int cnt = 0;
    ll pre = 0, ans = 0;
    for (int i = 0; i < events.size();) {
        ans += (cnt > 0) * (events[i].f - pre);
        do {
            cnt += events[i].s ? 1 : -1;
            pre = events[i].f;
            i++;
        } while (events[i].f == events[i - 1].f);
    }
    printf("%lld\n", ans);

    return 0;
}
