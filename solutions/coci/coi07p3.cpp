/*
 Solution to COI '07 #3 Tamnica by Ava Pun
 Key concepts: Dijkstra's
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll N;
int K;
ll arr[MAX];
vector<pair<int, bool>> adj[2 * MAX];
ll dist[2 * MAX];
bool vis[2 * MAX];
vector<ll> pts;

inline ll getA(ll b) {
    ll sq = ceil(sqrt(b));
    if (sq % 2 == 0) {
        sq++;
    }
    ll inner = (sq - 2) * (sq - 2);
    if (sq * sq == b) {
        return inner + 1;
    }
    return b - 4 * (sq - 3) - 2 * ((b - inner) / (sq - 1)) - 1;
}

inline void addEdge(int a, int b, bool d) {
    adj[a].pb({b, d});
    adj[b].pb({a, d});   
}

int main() {
    
    scanf("%lld%d", &N, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%lld", &arr[i]);
        pts.pb(arr[i]), pts.pb(getA(arr[i]));
    }

    pts.pb(1), pts.pb(N);
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (int i = 1; i <= K; i++) {
        addEdge((int) (lower_bound(pts.begin(), pts.end(), arr[i]) - pts.begin()), (int) (lower_bound(pts.begin(), pts.end(), getA(arr[i])) - pts.begin()), 0);
    }
    for (int i = 0; i < pts.size() - 1; i++) {
        addEdge(i, i + 1, 1);
    }
    N = (int) (lower_bound(pts.begin(), pts.end(), N) - pts.begin());

    FILL(dist, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; 
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<ll, int> x = pq.top();
        pq.pop();
        ll u = x.s;
        if (!vis[u]) {
            vis[u] = 1;
            for (pair<int, ll> e : adj[u]) {
                ll v = e.f, d0 = e.s, d;
                if (!d0) {
                    d = 1;
                } else {
                    d = abs(pts[v] - pts[u]);
                }
                if (!vis[v] && dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    printf("%lld\n", dist[N]);

    return 0;
}
