/*
 Solution to Another Contest 5 Problem 3 - Cutting Cheese Costs by Ava Pun
 Key concepts: implementation, greedy algorithms
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, K;
pii arr[MAX];

inline bool comp(pii a, pii b) {
    return a.f - a.s > b.f - b.s;
}

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    sort(arr + 1, arr + N + 1, comp);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i <= K) {
            ans += arr[i].s;
        } else {
            ans += arr[i].f;
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
