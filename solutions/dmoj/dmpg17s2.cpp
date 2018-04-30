/*
 Solution to DMPG '17 S2 - Anime Conventions by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, Q;
int par[MAX], ranks[MAX];

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return;
    }
    if (ranks[a] < ranks[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (ranks[b] == ranks[a]) {
            ranks[a]++;
        }
    }
}

int main() {

    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    char c;
    int a, b;
    while (Q--) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'A') {
            Union(a, b);
        } else {
            printf(Find(a) == Find(b) ? "Y\n" : "N\n");
        }
    }
    
    return 0;
}
