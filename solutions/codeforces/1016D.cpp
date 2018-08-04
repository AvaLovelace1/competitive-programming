/*
 Solution to Vasya And The Matrix by Ava Pun
 Key concepts: math
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
const int MAX = 3e5 + 5;

int N, M;
int rows[105], cols[105];
int mat[105][105];

int main() {
    
    scanf("%d%d", &N, &M);
    int xc = 0, xr = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &rows[i]);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d", &cols[i]);
    }
    
    for (int i = 1; i < N; i++) {
        mat[i][M] = rows[i];
        xr ^= rows[i];
    }
    for (int i = 1; i < M; i++) {
        mat[N][i] = cols[i];
        xc ^= cols[i];
    }
    if ((xr ^ cols[M]) == (xc ^ rows[N])) {
        mat[N][M] = xr ^ cols[M];
        printf("YES\n");
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
    
    return 0;
}
