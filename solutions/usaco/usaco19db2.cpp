/*
 * Solution to USACO '19 December B2 - Where Am I? by Ava Pun
 * Key concepts: implementation, brute force, set
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
const int MAX = 2e5 + 2;

int N;
string S;
set<string> ss;

int main() {

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 1; i <= N; ++i) {
        ss.clear();
        bool good = true;
        for (int j = 0; j + i - 1 < N; ++j) {
            if (ss.find(S.substr(j, i)) != ss.end()) {
                good = false;
                break;
            }
            ss.insert(S.substr(j, i));
        }
        if (good) {
            cout << i << '\n';
            break;
        }
    }

}
