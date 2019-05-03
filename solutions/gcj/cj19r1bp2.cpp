/*
 Solution to Google Code Jam '19 R1B P2 - Draupnir by Ava Pun
 Key concepts: mathematics
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int T, W;
ll ans[7];
const int n1 = 200, n2 = 50;

ll power(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else {
        ll ans = power(a * a, b / 2);
        if (b % 2 == 1) {
            ans *= a;
        }
        return ans;
    }
}

inline ll quer(int n) {
    ll ret;
    printf("%d\n", n);
    fflush(stdout);
    scanf("%lld", &ret);
    if (ret == -1) {
        exit(0);
    }
    return ret;
}

inline void answer() {
    for (int i = 1; i <= 6; i++) {
        printf("%lld", ans[i]);
        if (i == 6) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if (ret == -1) {
        exit(0);
    }
}

int main() {
    
    scanf("%d%d", &T, &W);
    
    for (int test = 1; test <= T; test++) {
        ll q = quer(n1);
        for (int i = 4; i <= 6; i++) {
            ans[i] = q / power(2, n1 / i);
            q %= power(2, n1 / i);
        }
        q = quer(n2);
        for (int i = 4; i <= 6; i++) {
            q -= ans[i] * power(2, n2 / i);
        }
        for (int i = 1; i <= 3; i++) {
            ans[i] = q / power(2, n2 / i);
            q %= power(2, n2 / i);
        }
        answer();
    }
    
    return 0;
}
