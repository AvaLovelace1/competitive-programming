/*
 * Solution to USACO '16 January B2 - Angry Cows by Ava Pun
 * Key concepts: implementation, simulation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N;
int arr[102];

int main() {

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int minI = i, maxI = i;
        int exL = i, exR = i;
        for (int t = 1; t <= N; ++t) {
            int newExL = -1;
            int newExR = -1;
            if (exL != -1) {
                int j = exL;
                while (j > 1 && arr[j - 1] >= arr[exL] - t) {
                    --j;
                }
                if (j != exL) {
                    newExL = j;
                    minI = min(minI, newExL);
                }
            }
            if (exR != -1) {
                int j = exR;
                while (j < N && arr[j + 1] <= arr[exR] + t) {
                    ++j;
                }
                if (j != exR) {
                    newExR = j;
                    maxI = max(maxI, newExR);
                }
            }
            exL = newExL;
            exR = newExR;
        }
        ans = max(ans, maxI - minI + 1);
    }
    cout << ans << '\n';

}
