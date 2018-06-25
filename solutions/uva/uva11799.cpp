/*
 Solution to 11799 - Horror Dash by Ava Pun
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
const int MAX = 20;

int T, N;

int main() {
    
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);
        int n, ans = -1;
        while (N--) {
            scanf("%d", &n);
            ans = max(ans, n);
        }
        printf("Case %d: %d\n", i, ans);
    }
    
    return 0;
}
