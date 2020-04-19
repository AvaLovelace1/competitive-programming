/*
 Solution to Google Code Jam '20 QR P1 - Vestigium by Ava Pun
 Key concepts: implementation
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T, N;
int arr[105][105];
int cnt[2][105];

int main() {

    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int trace = 0, rowCnt = 0, colCnt = 0;
        for (int i = 1; i <= N; i++) {
            trace += arr[i][i];
        }
        for (int i = 1; i <= N; i++) {
            FILL(cnt, 0);
            bool repeat[] = {0, 0};
            for (int j = 1; j <= N; j++) {
                cnt[0][arr[i][j]]++;
                if (cnt[0][arr[i][j]] > 1) {
                    repeat[0] = 1;
                }
                cnt[1][arr[j][i]]++;
                if (cnt[1][arr[j][i]] > 1) {
                    repeat[1] = 1;
                }
            }
            rowCnt += repeat[0];
            colCnt += repeat[1];
        }
        printf("Case #%d: %d %d %d\n", test, trace, rowCnt, colCnt);
    }

    return 0;
}
