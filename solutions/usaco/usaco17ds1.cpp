/*
 * Solution to USACO '17 December S1 - My Cow Ate My Homework by Ava Pun
 * Key concepts: prefix sum array, prefix min array
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

int N;
int arr[MAX];
int mn[MAX];

double calc(int i) {
    int len = N - i;
    return (double) (arr[i] - mn[i]) / len;
}

int main() {

    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        mn[i] = arr[i];
    }
    mn[N + 1] = INF;
    for (int i = N; i >= 1; --i) {
        arr[i] += arr[i + 1];
        mn[i] = min(mn[i], mn[i + 1]);
    }
    
    double ans = 0;
    for (int i = 2; i <= N - 1; ++i) {
        ans = max(ans, calc(i));
    }
    for (int i = 2; i <= N - 1; ++i) {
        if (abs(calc(i) - ans) < EPS) {
            cout << i - 1 << '\n';
        }
    }

}
