/*
 * Solution to USACO '17 December S2 - Milk Measurement by Ava Pun
 * Key concepts: ordered map
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

int N, G;
piii arr[MAX];

void ins(map<int, int> &mp, int x) {
    ++mp[x];
}
void era(map<int, int> &mp, int x) {
    --mp[x];
    if (mp[x] == 0) {
        mp.erase(x);
    }
}

int main() {

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> G;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f.f >> arr[i].f.s >> arr[i].s;
    }
    sort(arr + 1, arr + N + 1);

    map<int, int> milks;
    map<int, int> ctom;
    ins(milks, G);
    for (int i = 1; i <= N; ++i) {
        int cow = arr[i].f.s;
        ctom[cow] = G;
        ins(milks, G);
    }

    int prevBest = (*(--milks.end())).f;
    int prevNumBest = (*(--milks.end())).s;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {

        int cow = arr[i].f.s;
        int prevMilk = ctom[cow];
        int change = arr[i].s;

        era(milks, ctom[cow]);
        ctom[cow] += change;
        ins(milks, ctom[cow]);

        int best = (*(--milks.end())).f;
        int numBest = (*(--milks.end())).s;
        int milk = ctom[cow];

        if (prevMilk == prevBest) {
            if (prevNumBest == 1 && numBest == 1) {
                ans += milk != best;
            } else {
                ++ans;
            }
        } else {
            ans += milk == best;
        }

        prevBest = best;
        prevNumBest = numBest;
    }
    cout << ans << '\n';

}
