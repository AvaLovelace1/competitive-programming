/*
 Solution to ECOO '17 R3 P2 - Family Trees by Ava Pun
 Key concepts: implementation
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
const int MAX = 1e6 + 5;

int N;
int NC = 0;
map<int, int> adj[MAX];
int sz[MAX];

int main() {

    string str;
    for (int test = 1; test <= 10; test++) {
        cin >> N;
        for (int i = 0; i <= NC; i++) {
            adj[i].clear();
            sz[i] = 0;
        }
        NC = 0;
        for (int i = 1; i <= N; i++) {
            cin >> str;
            str += '.';
            int u = 0, p = -1;
            for (char c : str) {
                if (c == '.') {
                    if (p != -1) {
                        if (adj[p].find(u) == adj[p].end()) {
                            sz[p] = max(sz[p], u);
                            adj[p][u] = ++NC;
                        }
                        p = adj[p][u];
                    } else {
                        p = 0;
                    }
                    u = 0;
                } else {
                    u *= 10;
                    u += c - '0';
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < NC; i++) {
            ans = (ans + sz[i]) % MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}
