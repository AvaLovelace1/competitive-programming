/*
 Solution to MWC '15 #2 P5: Watchmeblink1 by Ava Pun
 Key concepts: difference array
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
const int MAX = 1e5 + 5;

int N, K, Q;
ll arr[4][MAX];

int main() {

    scanf("%d%d%d", &N, &K, &Q);
    int l, r, n, t;
    while (Q--) {
        scanf("%d%d%d%d", &l, &r, &n, &t);
        arr[t][l] += n, arr[t][r + 1] -= n;
    }
    for (int i = 1; i <= 3; i++) {
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            arr[i][j] += arr[i][j - 1];
            ans += arr[i][j] < K;
        }
        printf("%d\n", ans);
    }

    return 0;
}
