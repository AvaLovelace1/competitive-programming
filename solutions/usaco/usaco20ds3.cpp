/*
 * Solution to USACO '20 December S3 - Stuck in a Rut by Ava Pun
 * Key concepts: simulation, graph theory
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
const int MAX = 1002;

int N;
piii north[MAX], east[MAX];
bool stoppedN[MAX];
vi adj[MAX];
int KN = 0, KE = 0;
int ans[MAX];
bool vis[MAX];

bool comp(piii a, piii b) {
    return make_pair(make_pair(a.f.s, a.f.f), a.s) < make_pair(make_pair(b.f.s, b.f.f), b.s);
}

int solve(int u) {
    if (!vis[u]) {
        vis[u] = true;
        for (int v : adj[u]) {
            ans[u]++;
            ans[u] += solve(v);
        }
    }
    return ans[u];
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    char c;
    for (int i = 1; i <= N; ++i) {
        cin >> c;
        if (c == 'N') {
            ++KN;
            cin >> north[KN].f.f >> north[KN].f.s;
            north[KN].s = i;
        } else {
            ++KE;
            cin >> east[KE].f.f >> east[KE].f.s;
            east[KE].s = i;
        }
    }
    sort(north + 1, north + KN + 1);
    sort(east + 1, east + KE + 1, comp);

    for (int i = 1; i <= KE; ++i) {
        for (int j = 1; j <= KN; ++j) {
            int x1 = east[i].f.f;
            int y1 = east[i].f.s;
            int x2 = north[j].f.f;
            int y2 = north[j].f.s;
            int idx1 = east[i].s;
            int idx2 = north[j].s;
            if (!stoppedN[j] && x2 > x1 && y2 < y1) {
                int distY = y1 - y2;
                int distX = x2 - x1;
                if (distY > distX) {
                    adj[idx1].pb(idx2);
                    stoppedN[j] = true;
                } else if (distX > distY) {
                    adj[idx2].pb(idx1);
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        cout << solve(i) << '\n';
    }

}
