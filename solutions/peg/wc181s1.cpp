/*
 Solution to WC18 #1 - Inspiration by Ava Pun
 Key concepts: prefix sum array
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int R, C, K;
int arr[15][50005], pref[15][50005];

int main() {

    scanf("%d%d%d", &R, &C, &K);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &arr[j][i]);
        }
    }
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) {
            pref[j][i] = (arr[j][i] == 1) + pref[j][i - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[j][i] == 2) {
                ans += pref[j][i - 1] - pref[j][max(0, i - K - 1)] > 0;
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
