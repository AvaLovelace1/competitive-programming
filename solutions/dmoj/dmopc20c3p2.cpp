/*
 Solution to DMOPC '20 Contest 3 P2 - Bob and Parallel-Ks by Ava Pun
 Key concepts: two pointers, sorting, map
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
const int MAX = 2e5 + 2;
const double EPS = 1e-9;

int N, M, K;
int arr[22][MAX];
pii sorted[22][MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> K;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[j][i];
            sorted[j][i] = {arr[j][i], i};
        }
    }
    for (int i = 1; i <= N; ++i) {
        sort(sorted[i] + 1, sorted[i] + M + 1);
    }
    
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        int ptr = 1;
        for (int j = 1; j <= M; ++j) {
            while (ptr <= M && sorted[i][ptr].f < sorted[i][j].f + K) {
                ++ptr;
            }
            if (sorted[i][ptr].f - sorted[i][j].f == K) {
                int voice1 = sorted[i][j].s;
                int voice2 = sorted[i][ptr].s;
                ans += arr[i + 1][voice2] - arr[i + 1][voice1] == K;
            }
        }
    }
    cout << ans << '\n';
    
}
