/*
 Solution to Chef and Favourite Sequence by Ava Pun
 Key concepts: disjoint set
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M;
int par[MAX], ranks[MAX];

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return 0;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else if (ranks[b] < ranks[a]) {
        par[b] = a;
    } else {
        par[b] = a;
        ranks[a]++;
    }
    return 1;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N + 1; i++) {
        par[i] = i;
    }
    int a, b, n = 0;
    while (M--) {
        scanf("%d%d", &a, &b);
        if (Union(a, b + 1)) {
            n++;
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * 2 % MOD;
    }
    printf("%lld\n", ans);
    
    return 0;
}
