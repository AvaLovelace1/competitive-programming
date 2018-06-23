/*
 Solution to DMOPC '15 Contest 7 P3 - Harbourmaster by Ava Pun
 Key concepts: brute force
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
const int MAX = 30;

int req[3], N;
int arr[3][MAX];

int main() {

    scanf("%d%d%d%d", &req[0], &req[1], &req[2], &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &arr[0][i], &arr[1][i], &arr[2][i]);
    }
    
    double ans = 0;
    if (N < 5) {
        ans = INF;
        for (int i = 0; i < 3; i++) {
            ans = min(ans, accumulate(arr[i] + 1, arr[i] + N + 1, 0.0) / req[i] * 100);
        }
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                for (int k = j + 1; k <= N; k++) {
                    for (int l = k + 1; l <= N; l++) {
                        for (int m = l + 1; m <= N; m++) {
                            double tmp = INF;
                            for (int n = 0; n < 3; n++) {
                                tmp = min(tmp, (double) (arr[n][i] + arr[n][j] + arr[n][k] + arr[n][l] + arr[n][m]) / req[n] * 100);
                            }
                            ans = max(ans, tmp);
                        }
                    }
                }
            }
        }
    }
    
    printf("%.1lf\n", min(ans, 100.0));
    
    return 0;
}
