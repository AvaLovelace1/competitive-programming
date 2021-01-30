/*
 * Solution to USACO '20 February B1 - Triangles by Ava Pun
 * Key concepts: implementation, brute force
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 52;

int N;
pii arr[102];

int main() {

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f >> arr[i].s;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if (arr[i].f == arr[j].f && arr[i].s == arr[k].s) {
                    int area = abs(arr[i].s - arr[j].s) * abs(arr[i].f - arr[k].f);
                    ans = max(ans, area);
                }
            }
        }
    }
    cout << ans << '\n';

}
