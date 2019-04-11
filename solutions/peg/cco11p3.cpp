/*
 Solution to CCO '11 P3 - Spies Like Us by Ava Pun
 Key concepts: brute force, bitset cheese
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
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 2005;

int N, M, K;
bitset<MAX> adjN[MAX], adjM[MAX], tmp;

inline bool solve(int N, bitset<MAX> adj[]) {
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            tmp = adj[i] & adj[j];
            if (tmp.count() > 1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    scanf("%d%d%d", &N, &M, &K);
    int a, b;
    for (int i = 1; i <= K; i++) {
        scanf("%d%d", &a, &b);
        adjN[a][b] = 1;
        adjM[b][a] = 1;
    }
    bool ans = solve(N, adjN) && solve(M, adjM); 
    printf(ans ? "YES\n" : "NO\n");

    return 0;
}
