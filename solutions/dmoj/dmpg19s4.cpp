/*
 Solution to DMPG '19 S4 - Confusing Crossword Conundrum by Ava Pun
 Key concepts: BFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, Q;
string idxToStr[MAX];
vi adj[MAX];
bool vis[MAX];
int par[26][MAX];

inline int getIdx(string str) {
    return (int) (lower_bound(idxToStr + 1, idxToStr + N + 1, str) - idxToStr);
}

inline void bfs(char c) {
    FILL(vis, 0);
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (idxToStr[i][0] == c) {
            vis[i] = 1;
            par[c - 'A'][i] = i;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                par[c - 'A'][v] = par[c - 'A'][u];
                q.push(v);
            }
        }
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> idxToStr[i];
    }
    sort(idxToStr + 1, idxToStr + N + 1);
    string a, b;
    while (M--) {
        cin >> a >> b;
        int iA = getIdx(a), iB = getIdx(b);
        adj[iA].pb(iB);
        adj[iB].pb(iA);
    }

    for (int i = 0; i < 26; i++) {
        bfs(i + 'A');
    }

    char c;
    while (Q--) {
        cin >> a >> c;
        int iA = getIdx(a);
        int ans = par[c - 'A'][iA];
        cout << (ans == 0 ? "-1" : idxToStr[ans]) << '\n';
    }
    
    return 0;
}
