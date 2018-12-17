/*
 Solution to COCI '17 Contest 4 #1 Rasvjeta by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int N, M, K;
bool arr[MAX];

int main() {

    scanf("%d%d%d", &N, &M, &K);
    int x;
    while (M--) {
        scanf("%d", &x);
        for (int i = x; i <= x + K && i <= N; i++) {
            arr[i] = 1;
        }
        for (int i = x; i >= x - K && i >= 1; i--) {
            arr[i] = 1;
        }
    }

    arr[N + 1] = 1;
    int cnt = 0, ans = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (arr[i]) {
            ans += ceil((double) cnt / (2 * K + 1));
            cnt = 0;
        } else {
            cnt++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
