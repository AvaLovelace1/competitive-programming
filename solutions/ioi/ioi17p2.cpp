/*
 Solution to IOI '17 P2 - Wiring by Ava Pun
 Key concepts: dynamic programming, prefix array
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, M;
vii arr;
int link[MAX];
ll dp[MAX], fwdL[MAX], fwdR[MAX];

long long min_total_length(std::vector<int> r, std::vector<int> b) {
    
    N = (int) (r.size() + b.size());
    vii r1, b1;
    for (int i : r) {
        r1.pb({i, 0});
    }
    for (int i : b) {
        b1.pb({i, 1});
    }
    arr.resize(N);
    merge(r1.begin(), r1.end(), b1.begin(), b1.end(), arr.begin());
    arr.pb({1e9 + 1, 2});
    
    FILL(dp, INF), FILL(fwdL, INF), FILL(fwdR, INF);
    link[N] = N - 1, dp[N] = 0;
    int l = 0;
    ll tot = 0, gap = 0;
    
    for (int i = N - 1; i >= 0; i--) {

        if (arr[i].s != arr[i + 1].s) {
            link[i] = i;
            l = 0;
            tot = 0, gap = arr[i + 1].f - arr[i].f;
            for (int j = i + 1; j <= link[i + 1]; j++) {
                l++;
                tot += arr[j].f - arr[i + 1].f;
                fwdR[j] = tot + gap * l + min(dp[j], dp[j + 1]);
            }
            l = 0;
            for (int j = link[i + 1]; j >= i + 1; j--) {
                fwdL[j] = fwdR[j] + gap * l;
                l++;
            }
            for (int j = link[i + 1] - 1; j >= i + 1; j--) {
                fwdR[j] = min(fwdR[j], fwdR[j + 1]);
            }
            for (int j = i + 2; j <= link[i + 1]; j++) {
                fwdL[j] = min(fwdL[j], fwdL[j - 1]);
            }
            l = 0, tot = 0;
        } else {
            link[i] = link[i + 1];
        }
        
        l++;
        tot += arr[link[i]].f - arr[i].f;
        dp[i] = min(dp[i], tot + fwdL[min(link[link[i] + 1], link[i] + l)] - gap * (link[link[i] + 1] - link[i] - l));
        if (link[i] + l + 1 <= link[link[i] + 1]) {
            dp[i] = min(dp[i], tot + fwdR[link[i] + l + 1]);
        }
    }
    
    return dp[0];
}

int main() {

    scanf("%d%d", &N, &M);
    int n;
    vi r, b;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        r.pb(n);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &n);
        b.pb(n);
    }
    printf("%lld\n", min_total_length(r, b));
    
    return 0;
}
