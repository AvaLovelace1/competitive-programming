/*
 Solution to 10360 - Rat Attack by Ava Pun
 Key concepts: brute force, prefix sum array
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
const int MAX = 5e4 + 5;

int T, N = 1025, M, K;
int arr[1030][1030];

inline void trim(int &n) {
    n = max(n, 1), n = min(n, N);
}

inline int query(int r1, int c1, int r2, int c2) {
    trim(r1), trim(c1), trim(r2), trim(c2);
    return arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1];
}

int main() {
    
    scanf("%d", &T);
    
    while (T--) {
        
        FILL(arr, 0);
        scanf("%d%d", &K, &M);
        int r, c, n;
        while (M--) {
            scanf("%d%d%d", &r, &c, &n);
            r++, c++;
            arr[r][c] = n;
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
        
        int maxR = 0, maxC = 0, maxN = -1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int r1 = i - K, c1 = j - K, r2 = i + K, c2 = j + K;
                int ans = query(r1, c1, r2, c2);
                if (ans > maxN) {
                    maxN = ans, maxR = i, maxC = j;
                }
            }
        }
        
        printf("%d %d %d\n", maxR - 1, maxC - 1, maxN);
    }
    
    return 0;
}
