/*
 * Solution to USACO '16 December S1 - Counting Haybales by Ava Pun
 * Key concepts: binary search
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
const int MAX = 1e5 + 2;

int N, Q;
int arr[MAX];

int main() {

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);

    int a, b;
    while (Q--) {
        cin >> a >> b;
        cout << upper_bound(arr + 1, arr + N + 1, b) - lower_bound(arr + 1, arr + N + 1, a) << '\n';
    }

}
