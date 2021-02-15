/*
 * Solution to Boss Battle by Ava Pun
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

int N;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if (N <= 3) {
        cout << 1 << '\n';
    } else {
        cout << N - 3 + 1 << '\n';
    }

}
