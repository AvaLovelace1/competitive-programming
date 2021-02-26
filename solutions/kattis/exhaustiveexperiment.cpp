/*
 * Solution to Exhaustive Experiment by Ava Pun
 * Key concepts: monoqueue, convexity, greedy algorithms, sorting
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
using piii = pair<pii, char>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 2e5 + 5;

int N;

struct Com {
    int x, y;
    char type;
    bool underNHull, onPHull;
    void print() {
        cout << x << ' ' << y << ' ' << type << ' ' << underNHull << ' ' << onPHull << '\n';
    }
} arr[MAX];
vector<Com*> pHull;

bool comp(Com a, Com b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x < b.x;
}
bool compRev(Com a, Com b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x > b.x;
}

void findNHull() {
    int height = -INF;
    REP(i, 1, N) {
        auto &com = arr[i];
        if (com.type == 'N') {
            height = max(com.y, height);
        }
        if (com.y <= height) {
            com.underNHull = 1;
        }
    }
}

void findPHull() {
    REP(i, 1, N) {
        auto &com = arr[i];
        if (com.type == 'P') {
            while (!pHull.empty() && com.y <= pHull.back()->y) {
                pHull.pop_back();
            }
            pHull.pb(&com);
        }
    }
    for (auto &com : pHull) {
        com->onPHull = 1;
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    int x, y;
    char c;
    REP(i, 1, N) {
        cin >> x >> y >> c;
        x *= 2;
        arr[i] = Com{y - x, -x - y, c, false, false};
    }
    sort(arr + 1, arr + N + 1, comp);
    
    findNHull();
    findPHull();

    sort(arr + 1, arr + N + 1, compRev);

    pHull.clear();
    REV(i, N, 1) {
        auto &com = arr[i];
        if (com.onPHull) {
            pHull.pb(&com);
        }   
    }

    int ans = 0;
    Com *best = nullptr;
    REP(i, 1, N) {
        auto &com = arr[i];
        if (!com.underNHull && !pHull.empty() && com.y <= pHull.back()->y) {
            if (!best || com.y < best->y) {
                best = &com;
            }
        }
        if (com.onPHull) {
            if (best == nullptr) {
                cout << "impossible\n";
                return 0;
            } else {
                while (!pHull.empty() && pHull.back()->y >= best->y) {
                    pHull.back()->onPHull = 0;
                    pHull.pop_back();
                }
                ++ans;
                best = nullptr;
            }
        }
    }
    cout << ans << '\n';
    
}

