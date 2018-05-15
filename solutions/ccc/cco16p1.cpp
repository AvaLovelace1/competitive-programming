/*
 Solution to CCO '16 P1 - Field Trip by Ava Pun
 Key concepts: graph theory, DFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, M, K;
vi adj[MAX];
bool vis[MAX];

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    int num = 0, cut = 0;
    for (int i = 1; i <= N; i++) {
        
        if (!vis[i]) {
            
            stack<pii> st;
            st.push({i, -1});
            vis[i] = true;
            int cnt = 0;
            bool line = true;
            
            while (!st.empty()) {
                pii x = st.top();
                st.pop();
                cnt++;
                int u = x.f, prev = x.s;
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        st.push({v, u});
                    } else if (v != prev) {
                        line = false;
                    }
                }
            }
            
            num += cnt - cnt % K;
            if (cnt > K) {
                cut += ceil((double) cnt / K) - line;
            }
        }
        
    }
    printf("%d %d\n", num, cut);
    
    return 0;
}
