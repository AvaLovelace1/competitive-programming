/*
 Solution to DMOPC '14 Contest 2 P3 - Sawmill by Ava Pun
 Key concepts: greedy algorithms
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
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int N;
int eng[MAX], len[MAX];

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &eng[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &len[i]);
    }
    sort(eng + 1, eng + N + 1, greater<int>());
    sort(len + 1, len + N + 1);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (ll) eng[i] * len[i];
    }
    printf("%lld\n", ans);
    
    return 0;
}
