/*
 * Solution to Sum of Three Values by Ava Pun
 * Key concepts: two pointers
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
const int MAX = 5e5 + 5;

int N, X;
pii arr[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> X;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f;
        arr[i].s = i;
    }
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; ++i) {
        int k = N;
        for (int j = i + 1; j <= N; ++j) {
            while (k > j && (ll) arr[i].f + arr[j].f + arr[k].f > X) {
                --k;
            }
            if (k > j && (ll) arr[i].f + arr[j].f + arr[k].f == X) {
                cout << arr[i].s << ' ' << arr[j].s << ' ' << arr[k].s << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

}
