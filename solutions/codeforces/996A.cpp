/*
 Solution to Hit the Lottery by Ava Pun
 Key concepts: implementation
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
const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

int N;
int arr[] = {100, 20, 10, 5, 1};

int main() {

    scanf("%d", &N);
    ll ans = 0;
    int idx = 0;
    while (N) {
        ans += N / arr[idx];
        N %= arr[idx];
        idx++;
    }
    printf("%lld\n", ans);
    
    return 0;
}
