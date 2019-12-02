/*
 Solution to Friends of Friends by Ava Pun
 Key concepts: implementation, graph theory
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
const int MAX = 1e6 + 5;
const double EPS = 1e-9;

int N, X;
bool adj[55][55];
bool ans[55];

int main() {

    scanf("%d%d", &N, &X);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        int a;
        while (n--) {
            scanf("%d", &a);
            adj[i][a] = adj[a][i] = 1;
        }
    }

    int k = 0;
    for (int i = 1; i <= N; i++) {
        if (i != X && !adj[i][X]) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][j] && adj[j][X]) {
                    ans[i] = 1;
                    k++;
                    break;
                }
            }
        }
    }
    printf("%d\n", k);
    for (int i = 1; i <= N; i++) {
        if (ans[i]) {
            printf("%d", i);
            k--;
            printf(k == 0 ? "\n" : " ");
        }
    }

    return 0;
}
