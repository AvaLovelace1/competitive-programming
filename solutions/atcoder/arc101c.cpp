/*
 Solution to Candles by Ava Pun
 Key concepts: implementation, brute force
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
const int MAX = 1e5 + 5;

int N, K;
int arr[MAX];

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int pos = N + 1;
    for (int i = 1; i <= N; i++) {
        if (arr[i] >= 0 && pos == N + 1) {
            pos = i;
        }
    }
    int ans = INF;
    for (int i = 0; i <= K; i++) {
        if (pos + K - i - 1 <= N && pos - i >= 1 && K - i - 1 >= 0) {
            int a = i == 0 ? 0 : abs(arr[pos - i]);
            int b = i == pos ? 0 : arr[pos + K - i - 1];
            ans = min(ans, min(a, b) * 2 + max(a, b));
        }
    }
    if (pos - K >= 1) {
        ans = min(ans, abs(arr[pos - K]));
    }
    if (pos + K - 1 <= N) {
        ans = min(ans, arr[pos + K - 1]);
    }
    printf("%d\n", ans);
    
    return 0;
}
