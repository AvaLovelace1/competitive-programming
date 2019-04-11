/*
 Solution to CCO '11 P1 - Putnam by Ava Pun
 Key concepts: simple math
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
const int MAX = 1e5 + 5;

int N;
ll S;
pair<ll, double> arr[MAX];
ll rnk[MAX];

int main() {
        
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld%lf", &arr[i].f, &arr[i].s);
    }
    scanf("%lld", &S);
    sort(arr + 1, arr + N + 1, greater<pair<ll, double>>());

    rnk[1] = 1;
    for (int i = 1; i <= N; i++) {
        rnk[i + 1] = (ll) (2 * arr[i].s - rnk[i] + 1);
    }
    pair<ll, double> p = {S, 5e9};
    int idx = (int) (lower_bound(arr + 1, arr + N + 1, p, greater<pair<ll, double>>()) - arr);
    printf("%lld\n%lld\n", rnk[idx], rnk[idx + 1] - 1);

    return 0;
}
