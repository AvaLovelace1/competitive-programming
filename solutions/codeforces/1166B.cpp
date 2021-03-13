/*
 * Solution to All the Vowels Please by Ava Pun
 * Key concepts: constructive algorithms, number theory
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 5;

int K;
int arr[MAX];
const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

int factor(int k) {
    for (int i = 5; i * i <= k; ++i) {
        if (k % i == 0) return i;
    }
    return -1;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> K;

    int f1 = factor(K);
    if (f1 == -1) {
        cout << "-1\n";
    } else {
        int f2 = K / f1;
        REP(i, 0, f1 - 1) {
            REP(j, 0, f2 - 1) {
                cout << vowels[(i + j) % 5];
            }
        }
        cout << '\n';
    }
}

