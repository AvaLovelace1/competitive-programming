/*
 Solution to Max and Cards by Ava Pun
 Key concepts: implementation, mathematics
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
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e4 + 5;

int N, Q;
vi ans, used;

inline ll factorial(int n) {
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

void solve(int n, ll q) {
    if (n == 0) {
        for (int i : ans) {
            printf("%d ", i + 1);
        }
        printf("\n");
        return;
    }
    ll fact = factorial(n - 1);
    ans.pb(used[q / fact]);
    used.erase(used.begin() + q / fact);
    solve(n - 1, q % fact);
}

int main() {

    scanf("%d%d", &N, &Q);
    ll a;
    while (Q--) {
        scanf("%lld", &a);
        ans.clear(), used.clear();
        for (int i = 0; i < N; i++) {
            used.pb(i);
        }
        solve(N, a);
    }

    return 0;
}
