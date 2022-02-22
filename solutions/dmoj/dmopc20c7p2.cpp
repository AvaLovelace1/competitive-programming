/*
 Solution to DMOPC '20 Contest 7 P2 - Alice and Tiles by Ava Pun
 Key concepts: geometry, implementation
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
using piii = pair<pii, pii>;
using vi = vector<int>;
using vii = vector<piii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 2e5 + 5;

const pii squareDirs[] = {{0,0}, {0,1}, {1,1}, {1,0}};
const pii octDirs[] = {{0,-1}, {-1,0}, {-1,1}, {0,2}, {1,2}, {2,1}, {2,0}, {1,-1}};

int N;
vii edges;
map<pii, pii> mp;

bool operator<(pii a, pii b) { return a.f == b.f ? a.s < b.s : a.f < b.f; }

void canon(piii &x) { if (x.s < x.f) swap(x.f, x.s); }

bool comp(piii a, piii b) {
    canon(a), canon(b);
    return a.f == b.f ? a.s < b.s : a.f < b.f;
}

bool eq(piii a, piii b) {
    canon(a), canon(b);
    return a.f == b.f && a.s == b.s;
}

void addEdges(int x, int y, int D, const pii dirs[]) {
    REP(i, 0, D - 1) {
        auto dir1 = dirs[i], dir2 = dirs[(i + 1) % D];
        edges.emplace_back(
            make_pair(x + dir1.f, y + dir1.s),
            make_pair(x + dir2.f, y + dir2.s)
        ); 
    }
}

void addEdges(int x, int y) {
    if ((x/2 + y/2) % 2 == 0) addEdges(x, y, 4, squareDirs);
    else addEdges(x, y, 8, octDirs);
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> N;
    REP(i, 1, N) {
        int x, y;
        cin >> x >> y;
        addEdges(x, y);
    }

    sort(ALL(edges), comp);
    REP(i, 0, SZ(edges) - 1) {
        if (i != SZ(edges) - 1 && eq(edges[i], edges[i + 1])) ++i;
        else mp[edges[i].f] = edges[i].s;
    }

    cout << mp.size() << '\n';
    pii start = mp.begin()->f;
    pii v = start;
    do {
        cout << v.f << ' ' << v.s << '\n';
        v = mp[v];
    } while (v != start);

}
