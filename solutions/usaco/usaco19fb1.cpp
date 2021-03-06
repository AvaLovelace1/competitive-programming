/*
 * Solution to USACO '19 February B1 - Sleepy Cow Herding by Ava Pun
 * Key concepts: ad hoc
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
const int MAX = 2e5 + 5;

int arr[3];

int solveMin() {
    int mn = min(arr[1] - arr[0], arr[2] - arr[1]);
    int mx = max(arr[1] - arr[0], arr[2] - arr[1]);
    return mx == 1 ? 0 : (mn == 2 || mx == 2) ? 1 : 2;
}

int solveMax() {
    int mx = max(arr[1] - arr[0], arr[2] - arr[1]);
    return mx - 1;
}

int main() {

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    cout << solveMin() << '\n';
    cout << solveMax() << '\n';
}
