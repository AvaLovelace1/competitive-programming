/*
 Solution to Interesting Subarray by Ava Pun
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const double EPS = 1e-9;

int T, N;
int arr[MAX];

void solve() {
    for (int i = 2; i <= N; i++) {
        if (abs(arr[i] - arr[i - 1]) >= 2) {
            printf("YES\n%d %d\n", i - 1, i);
            return;
        }
    }
    printf("NO\n");
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]); 
        }
        solve();
    }

    return 0;
}
