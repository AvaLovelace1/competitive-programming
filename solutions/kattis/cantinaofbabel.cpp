/*
 * Solution to Cantina of Babel by Ava Pun
 * Key concepts: Tarjan's strongly connected components
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
const int MAX = 105;

int N;
string sp[105];
set<string> und[105];
vi adj[105];

int dfn[MAX], low[MAX];
bool vis[MAX];
stack<int> st1;
int numInComp[MAX];
int comp = 0;
int cnt = 1;

bool canTalkTo(int i, int j) {
    return und[j].find(sp[i]) != und[j].end();
}

void findscc(int u) {
    while (!st1.empty()) {
        int v = st1.top();
        st1.pop();
        dfn[v] = INF;
        ++numInComp[comp];
        if (v == u) {
            ++comp;
            return;
        }
    }
}

void tarjscc(int u) {

    dfn[u] = low[u] = cnt;
    vis[u] = true;
    cnt++;
    st1.push(u);

    for (int v : adj[u]) {
        if (!vis[v]) {
            tarjscc(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        findscc(u);
    }

}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string S;
    getline(cin, S);
    for (int i = 1; i <= N; ++i) {
        getline(cin, S);
        stringstream SS(S);

        string name;
        SS >> name;
        SS >> sp[i];

        und[i].insert(sp[i]);
        string lang2;
        while (SS >> lang2) {
            und[i].insert(lang2);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (canTalkTo(i, j)) {
                adj[i].pb(j);
            }
            if (canTalkTo(j, i)) {
                adj[j].pb(i);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            tarjscc(i);
            findscc(-1);
        }
    }

    int mx = *max_element(numInComp, numInComp + comp);
    cout << N - mx << '\n';

}
