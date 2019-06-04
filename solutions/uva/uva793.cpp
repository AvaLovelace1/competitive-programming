/*
 Solution to 793 - Network Connections by Ava Pun
 Key concepts: disjoint set, graph theory
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int T, N;
vi rnk, par;

int Find(int x) {
    if (par[x] != x) {
        par[x] = Find(par[x]);
    }
    return par[x];
}

inline bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) {
        return 0;
    }
    if (rnk[a] < rnk[b]) {
        swap(a, b);
    }
    par[b] = a;
    if (rnk[a] == rnk[b]) {
        rnk[a]++;
    }
    return 1;
}

int main() {

    scanf("%d", &T);
   
    while (T--) {
        scanf("%d", &N);
        rnk.resize(N + 1), par.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            rnk[i] = 0;
            par[i] = i;
        }
        int ans1 = 0, ans2 = 0;
        int a, b;
        char c = 'c';
        scanf("%*c%c", &c);
        while (c == 'c' || c == 'q') {
            scanf("%d%d", &a, &b);
            if (c == 'c') {
                Union(a, b);
            } else {
                if (Find(a) == Find(b)) {
                    ans1++;
                } else {
                    ans2++;
                }
            }
            if (scanf("%*c%c", &c) == EOF) {
                break;
            }
        }
        printf("%d,%d\n", ans1, ans2);
        if (T != 0) {
            printf("\n");
        }
    }

    return 0;
}
