/*
 Solution to DMPG '17 G5 - Vera and Pets by Ava Pun
 Key concepts: Dijkstra's, geometry, intersection of circles
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int N, X, Y;
int x[MAX], y[MAX], r[MAX];
vector<pair<int, lf>> adj[MAX];
lf dist[MAX];

inline lf area(int a) {
    return M_PI * r[a] * r[a];
}

inline int distSq(int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]); 
}

inline lf intersect(int a, int b) {
    if (r[a] > r[b]) {
        swap(a, b);
    }
    int dS = distSq(a, b);
    lf d = sqrt(dS);
    if ((r[a] + r[b]) * (r[a] + r[b]) < dS) {
        return -1;
    } else if ((r[a] + r[b]) * (r[a] + r[b]) == dS) {
        return 0;
    } else if (d + r[a] <= r[b]) {
        return M_PI * r[a] * r[a];
    } else {
        lf thetaA = acos((r[a] * r[a] - r[b] * r[b] + dS) / (2 * r[a] * d));
        lf thetaB = acos((-r[a] * r[a] + r[b] * r[b] + dS) / (2 * r[b] * d));
        lf sectors = thetaA * r[a] * r[a] + thetaB * r[b] * r[b];
        return sectors - sqrt((-d + r[a] + r[b]) * (d + r[a] - r[b]) * (d - r[a] + r[b]) * (d + r[a] + r[b])) / 2.0;
    }
}

int main() {

    scanf("%d%d%d", &N, &X, &Y);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (x[i] - r[i] <= 0 || y[i] + r[i] >= Y) {
            adj[0].pb({i, area(i)});
        }
        if (x[i] + r[i] >= X || y[i] - r[i] <= 0) {
            adj[i].pb({N + 1, 0});
        }
        for (int j = i + 1; j <= N; j++) {
            lf a = intersect(i, j);
            if (a != -1) {
                adj[i].pb({j, area(j) - a});
                adj[j].pb({i, area(i) - a});
            }
        }
    }

    fill(dist, dist + N + 2, INF);
    priority_queue<pair<lf, int>, vector<pair<lf, int>>, greater<pair<lf, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().s;
        pq.pop();
        for (auto e : adj[u]) {
            int v = e.f;
            lf d = e.s;
            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                pq.push({dist[v], v});
            }
        }
    }
    printf("%.9lf\n", dist[N + 1] == INF ? 0 : dist[N + 1]);
    
    return 0;
}
