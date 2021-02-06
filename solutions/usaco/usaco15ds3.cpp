/*
 * Solution to USACO '15 December S3 - Breed Counting by Ava Pun
 * Key concepts: prefix sum array
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

int N, Q;
int arr[4][MAX];

inline int quer(int l, int r, int pref[]) {
    return pref[r] - pref[l - 1];
}

int main() {

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    int x;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        arr[x][i] = 1;
        for (int j = 1; j <= 3; ++j) {
            arr[j][i] += arr[j][i - 1];
        }
    }
    int a, b;
    for (int i = 1; i <= Q; ++i) {
        cin >> a >> b;
        cout << quer(a, b, arr[1]) << ' ' << quer(a, b, arr[2]) << ' ' << quer(a, b, arr[3]) << '\n';
    }
    
}
