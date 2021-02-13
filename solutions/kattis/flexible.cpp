/*
 * Solution to Flexible Spaces by Ava Pun
 * Key concepts: implementation
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

int W, P;
int arr[105];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> P;
    arr[1] = 0;
    for (int i = 1; i <= P; ++i) {
        cin >> arr[i + 1];
    }
    arr[P + 2] = W;
    set<int> ss;
    for (int i = 1; i <= P + 2; ++i) {
        for (int j = i + 1; j <= P + 2; ++j) {
            ss.insert(arr[j] - arr[i]);
        }
    }
    int cnt = 0;
    for (int i : ss) {
        cout << i;
        ++cnt;
        if (cnt == ss.size()) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }

}
