/*
 * Solution to USACO '17 December B3 - Milk Measurement by Ava Pun
 * Key concepts: implementation, simulation
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
piii arr[102];
int milk[102];
bool winners[102];

int main() {

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    unordered_map<string, int> names;
    int K = 0;
    for (int i = 1; i <= N; ++i) {
        int day, val;
        string name;
        cin >> day >> name >> val;
        if (names.find(name) == names.end()) {
            ++K;
            names[name] = K;
        }
        arr[i] = {day, {names[name], val}};
    }
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= K; ++i) {
        milk[i] = 7;
        winners[i] = true;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int name = arr[i].s.f;
        int val = arr[i].s.s;
        milk[name] += val;
        int maxMilk = *(max_element(milk + 1, milk + K + 1));
        bool changed = false;
        for (int j = 1; j <= K; ++j) {
            bool won = milk[j] == maxMilk;
            if (won != winners[j]) {
                changed = true;
            }
            winners[j] = won;
        }
        if (changed) {
            ++ans;
        }
    }
    cout << ans << '\n';

}
