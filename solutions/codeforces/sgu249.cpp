/*
 Solution to Matrix by Ava Pun
 Key concepts: 2D prefix min array
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
const int MAX = 1005;
const double EPS = 1e-9;

int N, M;
int arr[MAX][MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = N - 1; j >= 1; j--) {
            arr[j][i] = min(arr[j][i], arr[j + 1][i]);
        }
    }
    int minN = INF;
    for (int i = M; i >= 1; i--) {
        minN = min(minN, arr[1][i]);
        arr[1][i] = min(arr[1][i], minN);
        for (int j = 1; 1 + j <= N && i - j >= 1; j++) {
            arr[1 + j][i - j] = min(minN, min(arr[1 + j][i - j], arr[1 + j - 1][i - j + 1]));
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; i + j <= N && M - j >= 1; j++) {
            arr[i + j][M - j] = min(arr[i + j][M - j], arr[i + j - 1][M - j + 1]);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
