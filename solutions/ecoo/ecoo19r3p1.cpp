/*
 Solution to ECOO '19 R3 P1 - Chords by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
bool inc[MAX];

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d", &N);
        FILL(inc, 0);
        int n;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &n);
            inc[n] = 1;
        }
        ll ans = 0;
        for (int i = 1; i <= 1000000; i++) {
            if (inc[i]) {
                for (int j = 2 * i; j <= 1000000; j += i) {
                    if (inc[j]) {
                        ans++;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
