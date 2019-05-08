/*
 Solution to ECOO '17 R3 P1 - Baker Brie by Ava Pun
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int F, D;
int arr[4750][135];

int main() {

    for (int test = 1; test <= 10; test++) {
        scanf("%d%d", &F, &D);
        ll ans = 0;
        for (int i = 1; i <= D; i++) {
            ll tot = 0;
            for (int j = 1; j <= F; j++) {
                scanf("%d", &arr[i][j]);
                tot += arr[i][j];
            }
            if (tot % 13 == 0) {
                ans += tot / 13;
            }
        }
        for (int j = 1; j <= F; j++) {
            int tot = 0;
            for (int i = 1; i <= D; i++) {
                tot += arr[i][j];
            }
            if (tot % 13 == 0) {
                ans += tot / 13;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
