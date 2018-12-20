/*
 Solution to COCI '17 Contest 4 #2 Izbori by Ava Pun
 Key concepts: bitmask brute force
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

int N, M, K;
int arr[105][16];
int votes[16];

int main() {

    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int minN = INF;
    for (int m = 0; m < (1 << M); m++) {
        FILL(votes, 0);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!(m & (1 << (arr[i][j] - 1)))) {
                    votes[arr[i][j]]++;
                    break;
                }
            }       
        }
        int win = (int) (max_element(votes + 1, votes + M + 1) - votes);
        if (m == 0) {
            printf("%d\n", win);
        }
        if (win == K) {
            minN = min(minN, __builtin_popcount(m));
        }
    }
    printf("%d\n", minN);

    return 0;
}
