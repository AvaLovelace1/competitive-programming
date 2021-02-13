/*
 * Solution to USACO '19 December B3 - Livestock Lineup by Ava Pun
 * Key concepts: brute force, permutations
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

int N;
map<string, vector<string>> adj;

bool is(vector<string> &v, int idx, string &str) {
    return idx >= 0 && idx < 8 && v[idx] == str;
}

bool good(vector<string> &v) {
    for (int i = 0; i < 8; ++i) {
        for (auto nxt : adj[v[i]]) {
            if (!is(v, i - 1, nxt) && !is(v, i + 1, nxt)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        string a, b;
        cin >> a;
        for (int j = 1; j <= 4; ++j) {
            cin >> b;
        }
        cin >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<string> v = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(v.begin(), v.end());
    do {
        if (good(v)) { 
            for (auto &str : v) {
                cout << str << '\n';
            }
            break;
        }
    } while (next_permutation(v.begin(), v.end()));

}
