/*
 Solution to WC17 #3 - Mutual Friends by Ava Pun
 Key concepts: graph theory, bitmask brute force
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
const int MAX = 1e6 + 5;

int N;
int arr[7][7];
bool adj[7][7];

int mutual(int a, int b) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (adj[i][a] && adj[i][b]) {
            cnt++;
        }
    }
    return cnt;
}

pii conv(int n) {
    n++;
    int i = 1, j = 1;
    for (i = 1; i <= N && n; i++) {
        for (j = i + 1; j <= N && n; j++) {
            n--;
        }
    }
    return {i - 1, j - 1};
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int tot = (N - 1) * N / 2;
    for (int cnt = 0; cnt < (1 << tot); cnt++) {
        FILL(adj, 0);
        for (int i = 0; i < tot; i++) {
            if (cnt & (1 << i)) {
                pii p = conv(i);
                adj[p.f][p.s] = 1;
                adj[p.s][p.f] = 1;
            }
        }
        bool found = true;
        for (int i = 1; i <= N && found; i++) {
            for (int j = i + 1; j <= N && found; j++) {
                if (mutual(i, j) != arr[i][j]) {
                    found = false;
                }
            }
        }
        if (found) {
            int M = 0;
            for (int i = 1; i <= N; i++) {
                for (int j = i + 1; j <= N; j++) {
                    if (adj[i][j]) {
                        M++;
                    }
                }
            }
            printf("%d\n", M);
            for (int i = 1; i <= N; i++) {
                for (int j = i + 1; j <= N; j++) {
                    if (adj[i][j]) {
                        printf("%d %d\n", i, j);
                    }
                }
            }
            return 0;
        }
    }
    
    printf("Impossible\n");
    
    return 0;
}
