/*
 Solution to IOI '17 P3 - Toy Train by Ava Pun
 Key concepts: graph theory, topological sort
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5000 + 5;

int N, M;
bool vis[MAX];
int indeg0[MAX], indeg[MAX];
vi rev[MAX];

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
    
    N = (int) a.size(), M = (int) u.size();
    for (int i = 0; i < M; i++) {
        rev[v[i]].pb(u[i]);
        indeg0[u[i]]++;
    }
    vi ans(N);
    fill(ans.begin(), ans.end(), 1);
    
    queue<int> q;
    bool done = 0;
    
    while (!done) {
        
        while (!q.empty()) {
            q.pop();
        }
        FILL(vis, 0);
        for (int i = 0; i < N; i++) {
            if (ans[i]) {
                indeg[i] = a[i] ? 1 : indeg0[i];
                if (r[i]) {
                    q.push(i);
                }
            }
        }
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : rev[x]) {
                indeg[y]--;
                if (indeg[y] == 0 && !vis[y] && ans[y]) {
                    vis[y] = 1;
                    if (!r[y]) {
                        q.push(y);
                    }
                }
            }
        }
        
        done = 1;
        for (int i = 0; i < N; i++) {
            if (!vis[i] && ans[i]) {
                ans[i] = 0;
                done = 0;
            }
        }
    }
    
    return ans;
}

int main() {
    
    scanf("%d%d", &N, &M);
    vi a(N), r(N), u(M), v(M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &r[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u[i], &v[i]);
    }
    vi ans = who_wins(a, r, u, v);
    for (int i : ans) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
