/*
 Solution to Relatively Prime Graph by Ava Pun
 Key concepts: graph theory, math, greedy algorithms
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

ll N, M;
vii edges;

inline void addEdge(int a, int b) {
    if (!M) {
        return;
    }
    edges.pb({a, b});
    M--;
}

int main() {
    
    scanf("%lld%lld", &N, &M);
    
    if (M < N - 1 || M > N * (N - 1) / 2) {
        printf("Impossible\n");
        return 0;
    }
    
    for (int i = 2; i <= N; i++) {
        addEdge(1, i);
    }
    for (int i = 2; i <= N && M; i++) {
        for (int j = 2; j < i && M; j++) {
            if (__gcd(i, j) == 1) {
                addEdge(i, j);
            }
        }
    }
    
    if (M == 0) {
        printf("Possible\n");
        for (pii p : edges) {
            printf("%d %d\n", p.f, p.s);
        }
    } else {
        printf("Impossible\n");
    }

    return 0;
}
