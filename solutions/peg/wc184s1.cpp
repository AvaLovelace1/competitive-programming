/*
 Solution to WC18 #4 - World of StarCraft by Ava Pun
 Key concepts: graph theory, connectivity, disjoint set
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

int N, M, K;
char owned[MAX];
int par[MAX], ranks[MAX];

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

bool Union(int a, int b) {
    
    a = Find(a);
    b = Find(b);
    
    if (a == b) {
        return false;
    }
    
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
    return true;
    
}

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &owned[i]);
        par[i] = i;
    }
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        if (owned[a] == owned[b]) {
            Union(a, b);
        }
    }
    int ans = 0;
    while (K--) {
        scanf("%d%d", &a, &b);
        ans += Find(a) == Find(b);
    }
    printf("%d\n", ans);
    
    return 0;
}
