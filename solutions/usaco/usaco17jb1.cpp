/*
 * Solution to USACO '17 January B1 - Don't Be Last! by Ava Pun
 * Key concepts: implementation, map
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
map<string, int> mp;

int main() {

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    mp["Bessie"] = 0;
    mp["Elsie"] = 0;
    mp["Daisy"] = 0;
    mp["Gertie"] = 0;
    mp["Annabelle"] = 0;
    mp["Maggie"] = 0;
    mp["Henrietta"] = 0;

    cin >> N;
    string S;
    int x;
    for (int i = 1; i <= N; ++i) {
        cin >> S >> x;
        mp[S] += x;
    }

    int min1 = INF;
    for (auto &p : mp) {
        min1 = min(min1, p.s);
    }
    int min2 = INF;
    for (auto &p : mp) {
        if (p.s != min1) {
            min2 = min(min2, p.s);
        }
    }
    if (min2 == INF) {
        cout << "Tie\n";
        return 0;
    }

    string best = "";
    for (auto &p : mp) {
        if (p.s == min2) {
            if (best != "") {
                cout << "Tie\n";
                return 0;
            } else {
                best = p.f;
            }
        }
    }
    cout << best << '\n';

}
