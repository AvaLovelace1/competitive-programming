/*
 * Solution to Bit Inversions by Ava Pun
 * Key concepts: ordered sets
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

int M, N;
string S;
set<int> bounds;
map<int, int> lengths;

void insert(map<int, int> &mp, int x) {
    ++mp[x];
}
void erase(map<int, int> &mp, int x) {
    --mp[x];
    if (mp[x] <= 0) {
        mp.erase(x);
    }
}

void upd(int x) {
    if (x > 1 && x <= N) {
        auto it = bounds.lower_bound(x);
        if (*it == x) {
            auto ub = it; ++ub;
            auto lb = it; --lb;
            erase(lengths, *ub - x);
            erase(lengths, x - *lb);
            insert(lengths, *ub - *lb);
            bounds.erase(x);
        } else {
            auto ub = it;
            auto lb = it; --lb;
            erase(lengths, *ub - *lb);
            insert(lengths, *ub - x);
            insert(lengths, x - *lb);
            bounds.insert(x);
        }
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> M;
    N = (int) S.length();
    S = ' ' + S;
    
    bounds.insert(1);
    bounds.insert(N + 1);
    insert(lengths, N);
    for (int i = 1; i <= N; ++i) {
        if (S[i] == '1') {
            upd(i), upd(i + 1);
        }
    }

    for (int i = 1; i <= M; ++i) {
        int x;
        cin >> x;
        upd(x), upd(x + 1);
        cout << (*(--lengths.end())).f << '\n';
    }

}
