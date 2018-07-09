/*
 Solution to Mock CCC '18 Contest 3 S4 - A Graph Problem by Ava Pun
 Key concepts: graph theory, ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<bool, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N;

int main() {
    
    scanf("%d", &N);
    int n;
    ll sum = 0;
    int maxN = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        sum += n;
        maxN = max(maxN, n);
    }
    printf(sum - maxN >= maxN && !(sum & 1) ? "YES\n" : "NO\n");
    
    return 0;
}
