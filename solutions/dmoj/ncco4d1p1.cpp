/*
 Solution to Mock CCO '18 Contest 4 Problem 1 - Mining for Minerals by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 20e3 + 5;

int N;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {

    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        pq.push(n);
    }
    
    ll ans = 0;
    while (pq.size() >= 2) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
