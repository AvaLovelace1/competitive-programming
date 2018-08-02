/*
 Solution to Intercity Travelling by Ava Pun
 Key concepts: math, combinatorics, probabilities
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
const int INF = 0x3F3F3F3F;
const int MOD = 998244353;
const int MAX = 1e6 + 5;

int N;
int arr[MAX];
ll power[MAX];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = power[i - 1] * 2 % MOD;
    }
    
    ll ans = 0, curr = 0;
    for (int i = 1; i <= N; i++) {
        curr = (curr - arr[i - 1] * power[N - i] % MOD + MOD) % MOD;
        curr = (curr + arr[i] * power[N - i] % MOD) % MOD;
        ans = (ans + curr) % MOD;
    }
    printf("%lld\n", ans);
    
    return 0;
}
