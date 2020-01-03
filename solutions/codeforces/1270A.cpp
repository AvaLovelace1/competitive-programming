/*
 Solution to Card Game by Ava Pun
 Key concepts: implementation, greedy algorithms
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
int K[2];
int arr[2][105];

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        scanf("%d%d", &K[0], &K[1]);
        for (int t = 0; t < 2; t++) {
            for (int i = 1; i <= K[t]; i++) { 
                scanf("%d", &arr[t][i]);
            }
            sort(arr[t] + 1, arr[t] + K[t] + 1);
        }
        printf(arr[0][K[0]] > arr[1][K[1]] ? "YES\n" : "NO\n");
    }

    return 0;
}
