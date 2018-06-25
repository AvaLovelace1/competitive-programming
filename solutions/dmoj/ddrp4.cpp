/*
 Solution to Double Doors Regional P4 - Tudor Teaches Jason How To Be Productive by Ava Pun
 Key concepts: BFS
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 505;

int N, Q;
string arr[MAX];
vi adj[MAX];
int dist[MAX][MAX];

bool edge(string A, string B) {
    if (abs((int) A.length() - (int) B.length()) > 1) {
        return 0;
    } else {
        if (A.length() == B.length()) {
            int cnt = 0;
            for (int i = 0; i < A.length(); i++) {
                if (A[i] != B[i]) {
                    cnt++;
                }
            }
            return cnt <= 1;
        } else {
            if (A.length() < B.length()) {
                swap(A, B);
            }
            int j = 0;
            for (int i = 0; i < A.length() && j < B.length(); i++) {
                if (A[i] != B[j]) {
                    if (i == j) {
                        j--;
                    } else {
                        return 0;
                    }
                }
                j++;
            }
            return 1;
        }
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (edge(arr[i], arr[j])) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    
    FILL(dist, INF);
    
    for (int i = 1; i <= N; i++) {
        
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[i][v] == INF) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    cin >> Q;
    int a, b;
    while (Q--) {
        cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }
    
    return 0;
}
