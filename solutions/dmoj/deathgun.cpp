/*
 Solution to Death Gun by Ava Pun
 Key concepts: graph theory, topological sort
 */

#include <bits/stdc++.h>

using namespace std;

int N;
map< string, int > names;
map< string, vector<string> > adj;
map< string, int > indeg;

struct comp {
    bool operator() (string s1, string s2) {
        return names[s1] > names[s2];
    }
};

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    string s1, s2;
    for (int i = 1; i <= N; i++) {
        cin >> s1 >> s2;
        adj[s2].push_back(s1);
        indeg[s1]++;
        if (indeg.find(s2) == indeg.end()) {
            indeg[s2] = 0;
        }
        if (names.find(s1) == names.end()) {
            names[s1] = i;
        }
        if (names.find(s2) == names.end()) {
            names[s2] = i;
        }
    }
    
    priority_queue< string, vector<string>, comp > pq;
    for (auto i : indeg) {
        if (i.second == 0) {
            pq.push(i.first);
        }
    }
    
    while (!pq.empty()) {
        s1 = pq.top();
        pq.pop();
        cout << s1 << "\n";
        for (string s : adj[s1]) {
            indeg[s]--;
            if (indeg[s] == 0) {
                pq.push(s);
            }
        }
    }
    
    return 0;
}
