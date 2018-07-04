/*
 Solution to The sum by Ava Pun
 Key concepts: implementation, simple math
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
const int MAX = 2e5 + 5;

int N;

int main() {
    
    scanf("%d", &N);
    if (N == 0) {
        printf("0\n");
        return 0;
    }
    int prev1 = 0, prev2 = 1, ans = 1;
    for (int i = 2; i <= N; i++) {
        int nxt = prev1 + prev2;
        ans += nxt;
        prev1 = prev2, prev2 = nxt;
    }
    printf("%d\n", ans);

    return 0;
}
