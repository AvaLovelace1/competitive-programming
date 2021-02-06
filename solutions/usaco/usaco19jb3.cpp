/*
 * Solution to USACO '19 January B3 - Guess the Animal by Ava Pun
 * Key concepts: brute force, set
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
set<string> arr[102];

int main() {

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string S;
    int K;
    for (int i = 1; i <= N; ++i) {
        cin >> S >> K;
        for (int j = 1; j <= K; ++j) {
            cin >> S;
            arr[i].insert(S);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int tot = 0;
            for (auto &str : arr[i]) {
                if (arr[j].find(str) != arr[j].end()) {
                    ++tot;
                }
            }
            ans = max(ans, tot + 1);
        }
    }
    cout << ans << '\n';

}
