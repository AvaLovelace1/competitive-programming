/*
 Solution to MEC '16 P6 - Instruments of the Ghostwriters by Ava Pun
 Key concepts: prefix sum/difference array, brute force
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
const int MOD = 1e9 + 7;
const int MAX = 45;

int C, R, M, Q;
ll row[3][MAX], col[3][MAX];
ll arr[MAX][MAX];
unordered_map<ll, int> mp;

void update(ll arr[][MAX], int l, int r, int n) {
    if (n != 0) {
        arr[0][l] *= n, arr[1][r + 1] *= n;
    } else {
        arr[2][l]++, arr[2][r + 1]--;
    }
}

void pref(ll arr[][MAX], int N) {
    for (int i = 1; i <= N; i++) {
        arr[0][i] = arr[0][i] * arr[0][i - 1] / arr[1][i];
    }
    for (int i = 1; i <= N; i++) {
        arr[2][i] += arr[2][i - 1];
    }
}

ll query(int x1, int y1, int x2, int y2) {
    return arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
}

int main() {
    
    scanf("%d%d%d%d", &C, &R, &M, &Q);
    fill(row[0], row[0] + 1 + R, 1);
    fill(col[0], col[0] + 1 + R, 1);
    fill(row[1], row[1] + 1 + R, 1);
    fill(col[1], col[1] + 1 + R, 1);
    FILL(row[2], 0), FILL(col[2], 0);
    
    char c;
    int a, b, n;
    while (M--) {
        scanf(" %c%d%d%d", &c, &a, &b, &n);
        if (c == 'r') {
            update(row, a, b, n);
        } else {
            update(col, a, b, n);
        }
    }
    pref(row, R), pref(col, C);
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            arr[i][j] = row[0][i] * col[0][j] * (!row[2][i] && !col[2][j]);
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            for (int k = i; k <= R; k++) {
                for (int l = j; l <= C; l++) {
                    mp[query(i, j, k, l)]++;
                }
            }
        }
    }
    
    ll B, O;
    while (Q--) {
        scanf("%lld%lld", &B, &O);
        if (B == 0 && O == 0) {
            printf("%d\n", C * (C + 1) * R * (R + 1) / 4);
        } else if ((B == 0 && O != 0) || O % B != 0) {
            printf("0\n");
        } else {
            printf("%d\n", mp[O / B]);
        }
    }
    
    return 0;
}
