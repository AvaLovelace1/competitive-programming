/*
 Solution to Google Kick Start '20 RB P2 - Bus Routes by Ava Pun
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T;
int N;
ll D;
ll arr[1005];

int main() {
    
    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        
        scanf("%d%lld", &N, &D);
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &arr[i]);
        }
        ll ans = D;
        for (int i = N; i >= 1; i--) {
            ans -= ans % arr[i];
        }
        
        printf("Case #%d: %lld\n", test, ans);
    }
    
    return 0;
} 
