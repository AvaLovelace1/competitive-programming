/*
 Solution to DMOPC '15 Contest 1 P5 - Lelei and Dragon Scales by Ava Pun
 Key concepts: 2D prefix sum array, brute force
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
const int MAX = 255;

int W, H, K;
int arr[255][255];

int query(int i1, int j1, int i2, int j2) {
    if (i1 < 0 || i1 > H || j1 < 0 || j1 > W || i2 < 0 || i2 > H || j2 < 0 || j2 > W) {
        return 0;
    }
    return arr[i2][j2] - arr[i1 - 1][j2] - arr[i2][j1 - 1] + arr[i1 - 1][j1 - 1];
}

int main() {

    scanf("%d%d%d", &W, &H, &K);
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
    
    int ans = -1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 1; j + k - 1 <= W; k++) {
                ans = max(ans, query(i, j, i + K / k - 1, j + k - 1));
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
