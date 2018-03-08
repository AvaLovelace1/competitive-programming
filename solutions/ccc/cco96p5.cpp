/*
 Solution to CCO '96 P5 - All Roads Lead Where? by Ava Pun
 Key concepts: graph theory, BFS, map
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;
unordered_map<string, bool> vis;
unordered_map<string, string> parent;
unordered_map<string, unordered_set<string>> adj;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    string s1, s2;
    while (N--) {
        cin >> s1 >> s2;
        adj[s1].insert(s2);
        adj[s2].insert(s1);
    }
    
    queue<string> q;
    while (Q--) {
        cin >> s1 >> s2;
        vis.clear();
        parent.clear();
        q.push(s1);
        parent[s1] = s1;
        vis[s1] = true;
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            for (string n : adj[x]) {
                if (!vis[n]) {
                    vis[n] = true;
                    parent[n] = x;
                    q.push(n);
                }
            }
        }
        stack<char> st;
        while (parent[s2] != s2) {
            st.push(s2[0]);
            s2 = parent[s2];
        }
        st.push(s2[0]);
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
    }
    
    return 0;
    
}
