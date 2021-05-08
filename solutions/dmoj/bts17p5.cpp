/*
 * Solution to Back to School '17: New English by Ava Pun
 * Key concepts: greedy algorithms
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

int N, M;
struct item {
    char c;
    int x, l, r;
};
vector<item> arr[26];
vector<item> open[MAX], close[MAX];

bool comp(item a, item b) {
    return a.r < b.r;
}

bool preprocess() {
    REP(i, 0, 25) {
        sort(ALL(arr[i]), comp);
        REV(j, SZ(arr[i]) - 1, 1) {
            auto &obj = arr[i][j];
            obj.x -= arr[i][j - 1].x;
            obj.l = arr[i][j - 1].r + 1;
            if (obj.x < 0) return 0;
            if (obj.l > obj.r && obj.x != 0) return 0;
        }
    }

    REP(i, 0, 25) {
        REP(j, 0, SZ(arr[i]) - 1) {
            auto &obj = arr[i][j];
            if (obj.l <= obj.r) {
                open[obj.l].pb(obj);
                close[obj.r].pb(obj);
            }
        }
    }
    return 1;
}

using pic = pair<int, char>;

string solve() {
    set<char> avail;
    REP(i, 0, 25) avail.insert((char) ('a' + i));
    priority_queue<pic, vector<pic>, greater<pic>> pq;
    string ret = "";

    REP(i, 1, N) {
        TRAV(obj, open[i]) {
            REP(k, 1, obj.x) pq.push({obj.r, obj.c});
            avail.erase(obj.c);
        }

        if (pq.empty()) {
            if (avail.empty()) return "-1";
            ret += *avail.begin();
        } else {
            if (pq.top().f < i) return "-1";
            ret += pq.top().s;
            pq.pop();
        }

        TRAV(obj, close[i]) {
            avail.insert(obj.c);
        }
    }

    if (!pq.empty()) return "-1";
    return ret;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;
    REP(i, 1, M) {
        char c;
        int x, idx;
        cin >> c >> x >> idx;
        arr[c - 'a'].pb(item{c, x, 1, idx});
    }
    if (!preprocess()) {
        cout << "-1\n";
        return 0;
    }

    cout << solve() << '\n';

}

